/*
 * Logger.h
 *
 *  Created on: Mar 29, 2016
 *      Author: dzhou
 */

#ifndef LOGGER_H_
#define LOGGER_H_

#include <string>
#include <fstream>
#include <sstream>
#include <iostream>
#include <ctime>
#include <chrono>

#include "SmartPointer.h"
#include "Concurrent.h"
#include "Exceptions.h"
#include "LocklessContainer.h"
#include "SysIO.h"

using std::string;
using std::ofstream;
using std::stringstream;

enum severity_type{DEBUG, INFO, WARNING, ERR};

class LogWriter : public Runnable {
public:
	LogWriter(const SmartPointer<BlockingBoundlessQueue<string>>& buffer, const string& fileName, long long sizeLimit);
	~LogWriter(){}

protected:
	virtual void run();

private:
	void archive();
	string createArchiveFileName() const;

private:
	SmartPointer<BlockingBoundlessQueue<string>> buffer_;
	string fileName_;
	long long sizeLimit_;
	int rowCount_;
	DataOutputStreamSP out_;
};

class Logger {
public:
	Logger() :  level_(INFO){}
	~Logger(){}
	bool start(const string& fileName, long long sizeLimit);
	void stop();
	void setLogLevel(severity_type level) { level_ = level;}

	template<severity_type severity , typename...Args>
	void print(Args...args ){
		stringstream stream;
		switch( severity ){
			case severity_type::DEBUG:
				if(level_ > DEBUG)
					return;
				stream<<"<DEBUG> :";
				break;
			case severity_type::INFO:
				if(level_ > INFO)
					return;
				stream<<"<INFO> :";
				break;
			case severity_type::WARNING:
				if(level_ > WARNING)
					return;
				stream<<"<WARNING> :";
				break;
			case severity_type::ERR:
				stream<<"<ERROR> :";
				break;
		};
		printImpl(stream, args... );
	}

private:
	void printImpl(stringstream& stream){
		buffer_->push(getTime() + " " + stream.str());
	}
	template<typename First, typename...Rest>
	void printImpl(stringstream& stream, First parm1, Rest...parm){
		stream<<parm1;
		printImpl(stream, parm...);
	}
	string getTime();

private:
	severity_type level_;
	SmartPointer<BlockingBoundlessQueue<string>> buffer_;
	ThreadSP thread_;
};

extern Logger log_inst;

#define LOG log_inst.print<severity_type::DEBUG>
#define LOG_ERR log_inst.print<severity_type::ERR>
#define LOG_INFO log_inst.print<severity_type::INFO>
#define LOG_WARN log_inst.print<severity_type::WARNING>




#endif /* LOGGER_H_ */
