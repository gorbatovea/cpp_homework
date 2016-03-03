Skip to content
This repository  
Search
Pull requests
Issues
Gist
 @gorbatovea
 Unwatch 1
  Star 0
  Fork 0 gorbatovea/cpp_homework
 Code  Issues 0  Pull requests 0  Wiki  Pulse  Graphs  Settings
cpp_homework/task2/ 
iBook.cpp
   or cancel
    
 Edit file    Preview changes


1
2
3
4
5
6
7
8
9
10
11
12
13
14
15
16
17
18
19
20
21
22
23
24
25
26
27
28
29
#include <time.h>
#include <stdlib.h>
#include <stdio.h>
#include<limits.h>
struct string{
public:
        char *ptr = NULL;
        int length;
        string(){
                length = 0;
        }
};
struct member{
        char *id = NULL;
        int idSize;
        char *name = NULL;
        int nameSize;
        char *number = NULL;
        int numberSize;
};
//interactions with file
FILE* IWF_OPEN_READ(const char *path){
        FILE *fp;
        if((fp = fopen(path,"r")) == NULL) {
                fp = fopen(path, "w");
                fclose(fp);
@gorbatovea
Commit changes


Update iBook.cpp

Add an optional extended description…
  Commit directly to the master branch
  Create a new branch for this commit and start a pull request. Learn more about pull requests.
Commit changes  Cancel
Status API Training Shop Blog About Pricing
© 2016 GitHub, Inc. Terms Privacy Security Contact Help
