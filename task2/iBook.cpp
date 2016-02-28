#include <time.h>
#include <stdlib.h>
#include <stdio.h>
#include<limits.h>

struct string{
public:
	char *ptr = NULL;
	int lentgth;
string(){
	lentgth = 0;
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
		fp = fopen(path,"r");
	}
	return fp;
}

void IWF_CLOSE(FILE *fp){
	fclose(fp);
	return;
}

FILE *IWF_OPEN_WRITE(const char *path){
	FILE *fp = fopen(path,"a");
	return fp;
}

FILE *IWF_OPEN_REWRITE(const char *path){
	FILE *fp;
	fp= fopen(path,"w");
	return fp;
}


//reading string from fileStream
string getStringFromFile(FILE *fp){
	string tmp; char c; int i = -1; tmp.ptr = NULL;

	while(true){
		c = fgetc(fp);
		if ((c !=' ') && (c != '\n') && (c != -1)){
			i++;
			if (i == 0) tmp.ptr =(char*) malloc(sizeof(char));
			else tmp.ptr = (char*) realloc(tmp.ptr,(i+1) * sizeof(char));
			tmp.ptr[i] = c;
		}
		else {
			tmp.lentgth = i+1;
			return tmp;
		}
	}
	tmp.ptr = NULL;
}

//this function using everytime when we need to take the next member from book
member readData(FILE *fp){
	struct member temp; struct string str;

	str = getStringFromFile(fp);
	temp.id = str.ptr; temp.idSize=str.lentgth;

	str = getStringFromFile(fp);
	temp.name = str.ptr; temp.nameSize = str.lentgth;

	str = getStringFromFile(fp);
	temp.number = str.ptr; temp.numberSize = str.lentgth;

	str.ptr = NULL; str.lentgth = 0;

	return temp;
}

//showing data of file
void printData(const char *path){
	FILE *fp = IWF_OPEN_READ(path);
	while (true) {
		member temp = readData(fp);
		if (temp.id == NULL) break;
		for (int i = 0; i < temp.idSize; i++) {
			printf("%c", temp.id[i]);
		}
		printf(" ");
		for (int i = 0; i < temp.nameSize; i++) {
			printf("%c", temp.name[i]);
		}
		printf(" ");
		for (int i = 0; i < temp.numberSize; i++) {
			printf("%c", temp.number[i]);
		}
		printf("\n");
	}
	IWF_CLOSE(fp);
}

//Checkers for related commands
bool cmdIsFind(char *cmd){
	if (cmd[0] != 'f') return false;
	if (cmd[1] != 'i') return false;
	if (cmd[2] != 'n') return false;
	if (cmd[3] != 'd') return false;
	return true;
}
bool cmdIsCreate(char *cmd){
	if (cmd[0] != 'c') return false;
	if (cmd[1] != 'r') return false;
	if (cmd[2] != 'e') return false;
	if (cmd[3] != 'a') return false;
	if (cmd[4] != 't') return false;
	if (cmd[5] != 'e') return false;
	return  true;
}
bool cmdIsDelete(char *cmd){
	if (cmd[0] != 'd') return false;
	if (cmd[1] != 'e') return false;
	if (cmd[2] != 'l') return false;
	if (cmd[3] != 'e') return false;
	if (cmd[4] != 't') return false;
	if (cmd[5] != 'e') return false;
	return true;
}
bool cmdIsChange(char *cmd){
	if (cmd[0] != 'c') return false;
	if (cmd[1] != 'h') return false;
	if (cmd[2] != 'a') return false;
	if (cmd[3] != 'n') return false;
	if (cmd[4] != 'g') return false;
	if (cmd[5] != 'e') return false;
	return true;
}
bool cmdIsExit(char *cmd){
	if (cmd[0] != 'e') return false;
	if (cmd[1] != 'x') return false;
	if (cmd[2] != 'i') return false;
	if (cmd[3] != 't') return false;
	return true;
}
bool cmdIsPrint(char *cmd){
	if (cmd[0] != 'p') return false;
	if (cmd[1] != 'r') return false;
	if (cmd[2] != 'i') return false;
	if (cmd[3] != 'n') return false;
	if (cmd[4] != 't') return false;
	return true;
}

//Getting search tag
string getTag() {
	string str;
	int i = -1;
	char c;
	while (true) {
		c = getchar();
		i++;
		if (i == 0) str.ptr = (char *) malloc(sizeof(char));
		else str.ptr = (char *) realloc(str.ptr, (i + 1) * sizeof(char));
		if ((c != ' ') && (c != '\n')) {
			str.ptr[i] = c;
			str.lentgth++;
		}
		else return str;
	}
}

void printMember(member tmp){
	for (int i = 0; i < tmp.idSize; i++){
		printf("%c",tmp.id[i]);
	}
	printf(" ");
	for (int i = 0; i < tmp.nameSize; i++){
		printf("%c",tmp.name[i]);
	}
	printf(" ");
	for (int i = 0; i < tmp.numberSize; i++){
		printf("%c",tmp.number[i]);
	}
	printf("\n");

}

bool compareChars(int c1, int c2){
	if ((abs(c1-c2) == 32) || c1 == c2) return true;
	return false;
}

string tagIsNumber(string tag){
	string tmp;
	tmp.ptr = (char*) malloc(sizeof(char));
	int i = -1;
	for (int j= 0; j < tag.lentgth; j++){
		if (((tag.ptr[j] >= 48) && (tag.ptr[j] <= 57)) || (tag.ptr[j] == 45) || (tag.ptr[j] == 40) || (tag.ptr[j] == 41) ){
				if ((tag.ptr[j] >= 48) && (tag.ptr[j] <= 57)) {
					i++;
					if (i == 0) tmp.ptr[i] = tag.ptr[j];
					else {
						tmp.ptr = (char*) realloc(tmp.ptr,(i+1) * sizeof(char));
						tmp.ptr[i] = tag.ptr[j];
					}
					tmp.lentgth++;
				}
		}
		else  {
			tmp.ptr = NULL;
			break;
		}
	}
	return tmp;
}

bool Digit(int c){
	if ((c >= 48) && (c <= 57)) return true;
	return false;
}

void searchByNumber(string tag,FILE *fp, const char *filePath){
	fp = IWF_OPEN_READ(filePath); member tmp;
	while (true){
		tmp = readData(fp);
		if (tmp.id == NULL) break;
		bool founded = false;
		int tagCounter = 0; int tmpCounter = 0;
		while(tmpCounter < tmp.numberSize){

			founded = true;
			if (!Digit(tmp.number[tmpCounter])) tmpCounter++;
				else{
				if (tmp.number[tmpCounter] != tag.ptr[tagCounter]) {
					founded = false;
					break;
				}
				else{
					tmpCounter++;
					tagCounter++;
				}
			}
			if (((tagCounter == tag.lentgth) && (tmpCounter!=tmp.numberSize)) || ((tagCounter != tag.lentgth) && (tmpCounter == tmp.numberSize)) ) {
				founded = false;
				break;
			}
		}
		if (founded) printMember(tmp);
	}
	IWF_CLOSE(fp);
}

//Find by tags
void find(FILE *fp, const char *filePath){
	//getting searchtag
	string tag = getTag();
	string tagNumber = tagIsNumber(tag);
	if (tagNumber.ptr != NULL){
		tag = tagNumber;
		searchByNumber(tag,fp,filePath);
		return;
	}
	member tmp; fp = IWF_OPEN_READ(filePath);
	while (true){
		tmp = readData(fp);
		if (tmp.id == NULL) break;
		bool founded =false;
		if(tag.lentgth <= tmp.nameSize){
			for (int i = 0; i <= tmp.nameSize - tag.lentgth; i++){
				if (founded) break;
				founded =  true;
				for (int j = 0; j < tag.lentgth; j++){
					if (!compareChars(tag.ptr[j],tmp.name[i+j])) founded =false;
				}
			}
		}
		if (founded) printMember(tmp);
	}
	IWF_CLOSE(fp);
}

string compareID(int newId, string currentId){
	string tmp;
	tmp.ptr = (char*) malloc(sizeof(char));
	tmp.lentgth = 1;
	int n =1;
	while (newId != 0){;
		char buf = (newId % 10*n) + '0';
		newId = newId / 10;
		if (tmp.lentgth == 1) tmp.ptr[tmp.lentgth-1] = buf;
		else {
			tmp.ptr = (char*) realloc(tmp.ptr, tmp.lentgth * sizeof(char));
			tmp.ptr[tmp.lentgth-1] = buf;
		}
		tmp.lentgth++;
	 }
	tmp.lentgth--;
	if (tmp.lentgth != currentId.lentgth) return tmp;
	else{
		bool equals = true;
		for (int i =0; i < tmp.lentgth; i++){
			if (tmp.ptr[i] != currentId.ptr[i]) equals = false;
		}
		if (equals) {
			tmp.ptr = NULL;
			tmp.lentgth = 0;
			return tmp;
		}
	}
	return tmp;
}

string generateId(FILE *fp, const char *filePath){
	fp = IWF_OPEN_READ(filePath);
	string tmp; member newMember;
	int r; int i = 0;
	while(true){
		i++;
		newMember = readData(fp);
		if ((i == 1) && (newMember.id == NULL)){
			r = rand() % INT_MAX;
			tmp = compareID(r,tmp);
			break;
		}
		if ((newMember.id == NULL) && tmp.ptr == NULL) tmp = generateId(fp,filePath);
		else if ((newMember.id == NULL) && (tmp.ptr !=NULL)) break;
		r = rand() % INT_MAX;
		tmp = compareID(r,tmp);
		if (tmp.ptr != NULL) break;
	}
	IWF_CLOSE(fp);
	return tmp;
}

void create(FILE *fp,const char *filePath){
	string tmp; member newMember;
	tmp = generateId(fp,filePath); newMember.id = tmp.ptr; newMember.idSize = tmp.lentgth;
	tmp = getTag(); newMember.name = tmp.ptr; newMember.nameSize = tmp.lentgth;
	tmp = getTag(); newMember.number = tmp.ptr; newMember.numberSize = tmp.lentgth;
	IWF_CLOSE(fp);
	IWF_OPEN_WRITE(filePath);
	for (int i = 0; i < newMember.idSize; i++){
		fwrite(&newMember.id[i],sizeof(char),1,fp);
		fflush(fp);
	}
	fwrite(" ",sizeof(char),1,fp);
	fflush(fp);
	for (int i = 0; i < newMember.nameSize; i++){
		fwrite(&newMember.name[i],sizeof(char),1,fp);
		fflush(fp);
	}
	fwrite(" ",sizeof(char),1,fp);
	fflush(fp);
	for (int i = 0; i < newMember.numberSize; i++){
		fwrite(&newMember.number[i],sizeof(char),1,fp);
		fflush(fp);
	}
	fwrite("\n",sizeof(char),1,fp);
	fflush(fp);
	IWF_CLOSE(fp);
}

bool searchById(string tag, member current){
	if (tag.lentgth != current.idSize) return false;
	for (int i = 0; i < tag.lentgth; i++){
		if (tag.ptr[i] != current.id[i]) return false;
	}
	return true;
}

void deleteId(string tag, const char *path){
	FILE *fp = IWF_OPEN_REWRITE("tmp");
	FILE *writeBackFile = IWF_OPEN_READ(path);
	while (true){
		member newMember = readData(writeBackFile);
		if (newMember.id == NULL) break;
		if (!searchById(tag,newMember)) {
			for (int i = 0; i < newMember.idSize; i++){
				fwrite(&newMember.id[i],sizeof(char),1,fp);
				fflush(fp);
			}
			fwrite(" ",sizeof(char),1,fp);
			fflush(fp);
			for (int i = 0; i < newMember.nameSize; i++){
				fwrite(&newMember.name[i],sizeof(char),1,fp);
				fflush(fp);
			}
			fwrite(" ",sizeof(char),1,fp);
			fflush(fp);
			for (int i = 0; i < newMember.numberSize; i++){
				fwrite(&newMember.number[i],sizeof(char),1,fp);
				fflush(fp);
			}
			fwrite("\n",sizeof(char),1,fp);
			fflush(fp);
		}
	}
	IWF_CLOSE(fp);
	IWF_CLOSE(writeBackFile);

	FILE *fileRead = IWF_OPEN_READ("tmp");
	FILE *fileWrite = IWF_OPEN_REWRITE(path);
	while (true){
		member newMember = readData(fileRead);
		if (newMember.id == NULL) break;
			for (int i = 0; i < newMember.idSize; i++){
				fwrite(&newMember.id[i],sizeof(char),1,fileWrite);
				fflush(fileWrite);
			}
			fwrite(" ",sizeof(char),1,fileWrite);
			fflush(fileWrite);
			for (int i = 0; i < newMember.nameSize; i++){
				fwrite(&newMember.name[i],sizeof(char),1,fileWrite);
				fflush(fileWrite);
			}
			fwrite(" ",sizeof(char),1,fileWrite);
			fflush(fileWrite);
			for (int i = 0; i < newMember.numberSize; i++){
				fwrite(&newMember.number[i],sizeof(char),1,fileWrite);
				fflush(fileWrite);
			}
			fwrite("\n",sizeof(char),1,fileWrite);
			fflush(fileWrite);
	}
	IWF_CLOSE(fileRead);
	IWF_CLOSE(fileWrite);
}

//getting command from console
void getCommand(FILE *fp, const char *filePath){
	string cmd; cmd.ptr=0; int i = -1;
	cmd.ptr = (char*) malloc(6 * sizeof(char));
	while (true){
		char c= getchar();
		while ((c != '\n') && (c != ' ')){
			i++;
			cmd.ptr[i] = c;
			if (i > 4) break;
			c = getchar();
		}
		bool cmdFound = false;
		//Ignore \n and ' '
		if ( (cmd.ptr[i] == '\n') || (cmd.ptr[i] == ' ') ) i = -1;

		//EXIT
		if( (i == 3) && cmdIsExit(cmd.ptr)){
			free(cmd.ptr);
			return;
		}
		//FIND
		if ( (i == 3) && cmdIsFind(cmd.ptr)) {
			cmdFound = true;
			find(fp,filePath);
			i = -1;
		}
		//CREATE
		if ( (i == 5) && cmdIsCreate(cmd.ptr)){
			create(fp,filePath);
			cmdFound = true;
			i = -1;
		}
		//DELETE
		if ( (i == 5) && cmdIsDelete(cmd.ptr)){
			deleteId(getTag(), filePath);
			cmdFound = true;
			i = -1;
		}
		//CHANGE
		if ( (i == 5) && cmdIsChange(cmd.ptr)){
			cmdFound = true;
			i = -1;
		}
		//Print all data
		if ( (i == 4) && cmdIsPrint(cmd.ptr)){
			printData(filePath);
			cmdFound = true;
			i = -1;
		}
		if ( (i != -1) && (!cmdFound)){
			printf("Error\n");
			i = -1;
		}
	}
}
int main(int argc, const char *argv[]) {
	const char *filePath = argv[1];
	FILE *fp = IWF_OPEN_READ(filePath);
	srand(time(0));
	getCommand(fp,filePath);
	printf("\nDONE!\n");
	return 0;
}
