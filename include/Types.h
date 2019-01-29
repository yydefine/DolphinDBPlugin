/*
 * Types.h
 *
 *  Created on: Jul 24, 2012
 *      Author: dzhou
 */


#ifndef TYPES_H_
#define TYPES_H_

#define DYAD_PRIORITY 10
#define MONAD_PRIORITY 0
#define RELATIONAL_PRIORITY 3
#define LOGIC_AND_PRIORITY 2

#define DELIMITOR_LINE 101
#define DELIMITOR_SEMI_COMMA 102
#define DELIMITOR_COMMENT 103

#define OPEN_DOUBLE_QUOTE 110
#define OPEN_SINGLE_QUOTE 111

#define BRACKET_LEFT_ROUND 201
#define BRACKET_RIGHT_ROUND 202
#define BRACKET_LEFT_SQUARE 203
#define BRACKET_RIGHT_SQUARE 204
#define BRACKET_LEFT_CURLY 205
#define BRACKET_RIGHT_CURLY 206

#define OPERATOR_MAP 301

#define CONSTANT_VOID 0
#define CONSTANT_BOOL 1
#define CONSTANT_CHAR 2
#define CONSTANT_SHORT 3
#define CONSTANT_INT 4
#define CONSTANT_LONG 5

#define CONSTANT_DATE 6
#define CONSTANT_MONTH 7
#define CONSTANT_TIME 8
#define CONSTANT_MINUTE 9
#define CONSTANT_SECOND 10
#define CONSTANT_DATETIME 11
#define CONSTANT_TIMESTAMP 12
#define CONSTANT_NANOTIME 13
#define CONSTANT_NANOTIMESTAMP 14

#define CONSTANT_FLOAT 15
#define CONSTANT_DOUBLE 16

#define CONSTANT_SYMBOL 17
#define CONSTANT_STRING 18
#define CONSTANT_DOUBLE_ENUM 19

#include <cfloat>
#include <string>

const double MC_PI = 3.1415926535897932384626433832795028841971693994L;
const double MC_E = 2.7182818284590452353602874713526624977572470937L;
const float FLT_ONE_LIMIT=0.9999999;
const double DBL_ONE_LIMIT=0.9999999999999;
const float FLT_NMIN=-FLT_MAX;
const double DBL_NMIN=-DBL_MAX;
const int MAX_SHARED_OBJ_INDEX = 65536;
const int MAX_FREEABLE_OBJ_COUNT = 512;
const size_t MAX_ARRAY_BUFFER = 16777216;
const int MAX_PEICE_FOR_PEICEWISE = 16;
const int MAX_POLYNOMIAL_ORDER = 128;
const int MAX_ROWS_FOR_MATRIX_COMPUTING = 8192;
const std::string functionKeyword = "def";
const std::string aggregationKeyword = "defg";
const std::string mapreduceKeyword = "mapr";

const int TYPE_COUNT = 28;

enum DATA_TYPE {DT_VOID,DT_BOOL,DT_CHAR,DT_SHORT,DT_INT,DT_LONG,DT_DATE,DT_MONTH,DT_TIME,DT_MINUTE,DT_SECOND,DT_DATETIME,DT_TIMESTAMP,DT_NANOTIME,DT_NANOTIMESTAMP,
	DT_FLOAT,DT_DOUBLE,DT_SYMBOL,DT_STRING,DT_UUID,DT_FUNCTIONDEF,DT_HANDLE,DT_CODE,DT_DATASOURCE,DT_RESOURCE,DT_ANY,DT_COMPRESS,DT_DICTIONARY,DT_OBJECT};

enum DATA_CATEGORY {NOTHING,LOGICAL,INTEGRAL,FLOATING,TEMPORAL,LITERAL,SYSTEM,MIXED};

/**
 * The order of the enumerated DATA_FORM items matters. In Constant class, we use 4 bits rather than a enum variable to
 * indicate the data form of the constant object. In other words, the value of each DATA_FORM instance is hard coded, i.e.
 * DF_SCALAR = 0
 * DF_VECTOR = 1
 * DF_PAIR = 2
 * DF_MATRIX = 3
 * DF_SET = 4
 * DF_DICTIONARY = 5
 * DF_TABLE = 6
 * DF_CHART = 7
 * DF_CHUNK = 8
 *
 * In case we have to change the value, please review the constructor of Constant, Vector, Set, Dictionary, and Table.
 */
enum DATA_FORM {DF_SCALAR,DF_VECTOR,DF_PAIR,DF_MATRIX,DF_SET,DF_DICTIONARY,DF_TABLE,DF_CHART,DF_CHUNK};

enum WORD_TYPE {KEYWORD,ENUM,CONSTANT,VARIABLE,FUNCNAME,GLOBALVARIABLE,OPERATOR,FUNCPATTERN,ASSIGNMENT,REFERENCE,BRACKET,DELIMITOR,COMMA,NAMESPACE,UNKNOWN};

enum STATEMENT_TYPE {IF,DO,FOR,ASSIGN,ATTRASSIGN,MULTIASSIGN,GLOBALASSIGN,PROCEDURE,RETURN,CONTINUE,BREAK,EMPTY,ADHOC,SHOWTIME,INSERT,UPDATE,DEL,ASSERT,ANNOTATE,
	TRYCATCH,THROW,MODULE,USE,SHARE,INCLUDE,JITHEADER,MAX_STMT_TYPES};

enum OBJECT_TYPE {CONSTOBJ,VAR,GLOBAL,ATTR,DIM,TUPLE,FUNCTION,EXPRESSION,COLUMN,COLUMNDEF,SQLQUERY,TABLEJOINER,VIRTUALCONST,MAPPEDCOL,GLOBALTABLE,MAX_OBJECT_TYPES};

enum TABLE_TYPE {BASICTBL,REALTIMETBL,SNAPTBL,FILETBL,CHUNKTBL,JOINTBL,SEGTBL,ALIASTBL,COMPRESSTBL,LOGROWTBL,MVCCTBL,CUSTOMIZEDTBL};

enum IO_ERR {OK,DISCONNECTED,NODATA,NOSPACE,TOO_LARGE_DATA,INPROGRESS,INVALIDDATA,END_OF_STREAM,READONLY,WRITEONLY,NOTEXIST,CORRUPT,OTHERERR};

enum CONSOLE_TYPE {STD,HTTP,TERMINAL,API,API2,JSON,BATCHJOB,UNSUPPORTED};

enum HANDLE_TYPE {FILE_HANDLE,SOCKET_HANDLE,REMOTE_HANDLE,DB_HANDLE};

enum FUNCTIONDEF_TYPE {SYSFUNC, SYSPROC, OPTRFUNC, USERDEFFUNC, PARTIALFUNC, DYNAMICFUNC, PIECEWISEFUNC};

enum FUNCTIONCALL_TYPE {THREADCALL, REGULARCALL, TEMPLATECALL};

enum CHART_TYPE {CT_AREA, CT_BAR, CT_COLUMN, CT_HISTOGRAM, CT_LINE, CT_PIE, CT_SCATTER};

enum OUTPUT_TYPE {STDOUT, HTTPOUT, APIOUT, LOGOUT, JOBOUT};

enum PARTITION_TYPE {SEQ, VALUE, RANGE, LIST, HIER, HASH};

enum SERVER_TYPE {DATANODE, AGENT, CONTROLLER};

enum TranCmdType{NEW_FILE, REPLACE_FILE, UPDATE_HEADER_APPEND, APPEND_FILE, UPDATE_FILE_HEADER, RENAME_FILEDIR, INMEMORY_CHANGE};

enum CHUNK_TYPE{FILE_CHUNK, TABLET_CHUNK, SPLIT_TABLET_CHUNK, SMALLFILE_CHUNK, ADDITIONAL_CHUNK};

enum DURATION_UNIT {DU_NANOSECOND,DU_MICROSECOND,DU_MILLISECOND,DU_SECOND,DU_MINUTE,DU_HOUR,DU_DAY,DU_WEEK,DU_MOUNTH,DU_YEAR};

enum STREAM_TYPE {ARRAY_STREAM, SOCKET_STREAM, FILE_STREAM, BIGARRAY_STREAM, FILEBLOCK_STREAM, OBJECT_STREAM};

enum ACL_ACCESS_TYPE: short {TABLE_READ, TABLE_WRITE, DBOBJ_CREATE, DBOBJ_DELETE, DB_MANAGE, VIEW_EXEC, SCRIPT_EXEC, TEST_EXEC, MAX_PRIORITY_ACCESS, MAX_PARALLELISM_ACCESS};

#ifdef INDEX64
	typedef long long INDEX;
	typedef unsigned long long UINDEX;
	#define DT_INDEX DT_LONG
	#define INDEX_MIN LLONG_MIN
	#define INDEX_MAX LLONG_MAX
#else
	typedef int INDEX;
	typedef unsigned int UINDEX;
	#define DT_INDEX DT_INT
	#define INDEX_MIN INT_MIN
	#define INDEX_MAX INT_MAX
#endif

typedef union {
	long long longVal;
	int intVal;
	short shortVal;
	char charVal;
	double doubleVal;
	float floatVal;
	char* pointer;
	int intArray[2];
	float floatArray[2];
	short shortArray[4];
	char charArray[8];
} U8;

typedef union {
	float floatVal;
	int intVal;
#ifdef BIT32
	char* pointer;
#endif
	short shortVal;
	char charVal;
	short shortArray[2];
	char charArray[4];
} U4;

#endif /* TYPES_H_ */
