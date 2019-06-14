void getInt(char mensaje[], int* auxiliar);
void getFloat(char mensaje[], float* auxiliar);
void getChar(char mensaje[], char* auxiliar);

char getNumeroAleatorio(int desde , int hasta, int iniciar);

int esNumerico(char str[]) ;
int esTelefono(char str[]);
int esAlfaNumerico(char str[]);
int esSoloLetras(char str[]);
int esNumericoFlotante(char str[]);

void getString(char mensaje[],char input[]);
int getStringLetras(char mensaje[],char input[]);
int getStringNumeros(char mensaje[],char input[]);
int getStringNumerosFlotantes(char mensaje[],char input[]);

int orderInt(char mensaje[], int* dato, int tam, int lado);
int calcularMaxOMin(int* array, int tam, int option);
void stringToUpper(char caracter[]);
