#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

int delaytime(){
	int time;
	printf("\nPlease insert the delay for each change (in seconds)\n\n");
	scanf("%d", &time);
	return time;
}

int* randomizer(float array[16]){
	srand(time(NULL)); 
//	cl_crosshairstyle = rand() % 3 + 2; //2,3,4 
//	cl_crosshaircolor_r = rand() % 256; //0..255
//	cl_crosshaircolor_g = rand() % 256; //0..255
//	cl_crosshaircolor_b = rand() % 256; //0..255
//	cl_crosshairalpha = rand() % 201 + 55; // 55..255
//	cl_crosshairdot = rand() % 2; //0,1
//	cl_crosshairsize = rand() % 501; //0..500
//	cl_crosshairgap = rand() % 501 - 250; //-250..250
//	cl_crosshairthickness = rand() % 36 / 10 + 0.5; //0.5...4
//	cl_crosshair_drawoutline = rand() % 2; //0,1
//	cl_crosshair_outlinethickness = rand() % 30 / 10 + 0.1; //0.1...3
//	cl_crosshairgap_useweaponvalue = rand() % 2; //0,1
//	cl_crosshair_dynamic_maxdist_splitratio = rand() % 101 / 100; //0...1
//	cl_crosshair_dynamic_splitalpha_innermod = rand() % 101 / 100; //0...1
//	cl_crosshair_dynamic_splitalpha_outermod = rand() % 71 / 10 + 0.3; //0.3...1
//	cl_crosshair_t = rand() % 2; //0,1
	array[0] = rand() % 3 + 2;
	array[1] = rand() % 256;
	array[2] = rand() % 256;
	array[3] = rand() % 256;
	array[4] = rand() % 201 + 55;
	array[5] = rand() % 2;
	array[6] = rand() % 501;
	array[7] = rand() % 501 - 250;
	array[8] = (float)rand() / (float)(RAND_MAX/36) / 10 + 0.5;
	array[9] = rand() % 2;
	array[10] = (float)rand() / (float)(RAND_MAX/30) / 10 + 0.1;
	array[11] = rand() % 2;
	array[12] = (float)rand() / (float)(RAND_MAX/101) / 100; 
	array[13] = (float)rand() / (float)(RAND_MAX/101) / 100;
	array[14] = (float)rand() / (float)(RAND_MAX/71) / 10 + 0.3;
	array[15] = rand() % 2;
}

char * getpath(char string[150]){
	char aux[150];
	printf("Please insert the full path to the cfg folder\nIT WILL REPLACE ANY FILE CALLED randcrosshair.cfg\n\n");
	fgets(aux, 150, stdin);
	int len = strlen(aux);
	if (aux[len-1] == '\n')
		aux[len-1] = '\0';
	sprintf(string, "%s\\randcrosshair.cfg", aux);
	fflush(stdin);
}

void delay(int seconds) 
{ 
    int milliseconds = 1000 * seconds; 
    clock_t start = clock(); 
    while (clock() < start + milliseconds); 
} 

int main(void){
	char path[150]; 
	getpath(path);
	int wait = delaytime();
	float randomized[16];
	
	while(1){
		randomizer(randomized);
		FILE *file;
		file = fopen (path, "w");
		fprintf(file, "%s%.0f%s", "cl_crosshairstyle \"",randomized[0],"\"\n");
		fprintf(file, "%s", "cl_crosshaircolor \"5\"\n");
		fprintf(file, "%s%.0f%s", "cl_crosshaircolor_r \"",randomized[1],"\"\n");
		fprintf(file, "%s%.0f%s", "cl_crosshaircolor_g \"",randomized[2],"\"\n");
		fprintf(file, "%s%.0f%s", "cl_crosshaircolor_b \"",randomized[3],"\"\n");
		fprintf(file, "%s%.0f%s", "cl_crosshairalpha \"",randomized[4],"\"\n");
		fprintf(file, "%s%.0f%s", "cl_crosshairdot \"",randomized[5],"\"\n");
		fprintf(file, "%s%.0f%s", "cl_crosshairsize \"",randomized[6],"\"\n");
		fprintf(file, "%s%.0f%s", "cl_crosshairgap \"",randomized[7],"\"\n");
		fprintf(file, "%s%.1f%s", "cl_crosshairthickness \"",randomized[8],"\"\n");
		fprintf(file, "%s%.0f%s", "cl_crosshair_drawoutline \"",randomized[9],"\"\n");
		fprintf(file, "%s%.1f%s", "cl_crosshair_outlinethickness \"",randomized[10],"\"\n");
		fprintf(file, "%s%.0f%s", "cl_crosshairgap_useweaponvalue \"",randomized[11],"\"\n");
		fprintf(file, "%s%.2f%s", "cl_crosshair_dynamic_maxdist_splitratio \"",randomized[12],"\"\n");
		fprintf(file, "%s%.2f%s", "cl_crosshair_dynamic_splitalpha_innermod \"",randomized[13],"\"\n");
		fprintf(file, "%s%.1f%s", "cl_crosshair_dynamic_splitalpha_outermod \"",randomized[14],"\"\n");
		fprintf(file, "%s%.0f%s", "cl_crosshair_t \"",randomized[15],"\"\n");
		fclose(file);
		printf("Crosshair changed! \n");
		delay(wait);
	}
	return 0;
}


