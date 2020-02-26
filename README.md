# Taxi-dictionary-retrival
## Introduction:
The purpose of this project is to build a dictionary for looking up information about for-hire trips in New York City. A binary tree will be used as the underlying data structure.

There are two stages of this project:

+ 1st stage: insert records into this dictionary and look up records by key

+ 2nd stage: retrieve information from this dictionary

## Specs:
The input data using in this project is retrieved from [the New York City Taxi & Limousine Commission](https://www1.nyc.gov/site/tlc/about/tlc-trip-record-data.page).
  
Assume that input data is well-formated, input file is not empty and the maximun length of an record is 256 characters.
  
## How it works:

### Stage 1: Build dictionary.
Create a Makefile will direct compilation to produce an executable program. It will take two command line arguments: the first one is the name of the input file used to build the dictionary and second one is the name of the output file contain data get fromt the search.

Construct a binary dictionary to store data information using <PUdatatime> which is presented the date and time of the taxi trip in format YYYY-MM-DD HH:mm:ss as the look up <key> and other data fields will be treated simply as <data>. For duplicated keys, I will handle by linked lists. 
  
They key will be read from `stdin` and then search through the binary tree for the records. For testing conveniency, I will be the UNIX operator < to redirect `keyfile`.

The program will look up each key and output the information to the output file specified in the command line. If the key is not found in the tree, output is the word `NOT FOUND`. If there is more than one data get from a specific key, the output should contain all the data.

The number of key comparisons perfomrmed during both successful and unsuccessful lookups will be written to stdout.

For example:

If the keyfile contain these value: 
+ 2018-12-15 01:49:13

+ 2018-12-15 01:49:13

+ 1901-11-06

Output file should be:
+ 2018-12-15 01:49:13 --> VendorID: 1 || passenger count: 1 || trip distance: 1.9
|| RatecodeID: 1.0 || store and fwd flag: 0 || PULocationID: 79 || DOLocationID: 234 ||
payment type: 1 || fare amount: 9.5 || extra: 0.5 || mta tax: 0.5 || tip amount: 2.15
|| tolls amount: 0.0 || improvement surcharge: 0.3 || total amount: 12.95 || DOdatetime:
2018-12-15 02:00:00 || trip duration: 10 ||
+ 2018-12-15 01:49:13 --> VendorID: 1 || passenger count: 1 || trip distance: 0.6
|| RatecodeID: 1.0 || store and fwd flag: 0 || PULocationID: 79 || DOLocationID: 114 ||
payment type: 1 || fare amount: 5.0 || extra: 0.5 || mta tax: 0.5 || tip amount: 1.00
|| tolls amount: 0.0 || improvement surcharge: 0.3 || total amount: 7.35 || DOdatetime:
2018-12-02 01:53:38 || trip duration: 4 ||
+ 1901-11-06 12:03:14 --> NOTFOUND

And `stdout`: 
+ 2018-12-15 01:49:13 --> 423
+ 1901-11-06 12:03:14 --> 401

### Stage 2: 
In stage 2, the lookup keys will be <PULocationID> and the output file wil contain all of the <PUdatetime> keys. The method for looking information should be in-order tree traversal. 

As in stage 1, I also create a Makefile and output the number of comparions used to `stdout`.

For example: 

If the keyfiles contain: 79 

The output file:
+ 79 --> 2018-12-08 19:36:57
+ 79 --> 2018-12-08 21:22:08
+ 79 --> 2018-12-15 01:49:13
+ 79 --> 2018-12-15 01:49:13
+ 79 --> 2018-12-23 17:26:42

The `stdout`: 
+ 79 --> 1528

## Note:
This project is a university assignment from Algorithms & Data Structure subject in The University of Melbourne, Department of Computing  and Software System, Semester 2 2019.
