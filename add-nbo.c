#include<stdio.h>
#include<netinet/in.h>


union Value {
	char ch;
	uint32_t Int;
};


int main(int argc, char **argv){
	FILE* aFile = fopen(argv[1], "r");
	FILE* bFile = fopen(argv[2], "r");
	
	if( argc != 3 ){
		printf("syntax : add-nbo <file1> <file2>\n");
		return 0;
	}
	
	if( aFile == NULL ){
		printf("do not find %s",argv[1]);
		return 0;
	}

	if( bFile == NULL ){
		printf("do not find %s",argv[2]);
		return 0;
	}


	union Value a; 
	union Value b;
	union Value r;

	fgets(&a.ch, 5, aFile);
	fgets(&b.ch, 5, bFile);
	a.Int = htonl(a.Int);
	b.Int = htonl(b.Int);
	printf("a : %x\n",a.Int);
	printf("b : %x\n",b.Int);
	r.Int = a.Int + b.Int;
	printf("c : %x\n",r.Int);




	fclose(bFile);
	fclose(aFile);
	return 0;
}
