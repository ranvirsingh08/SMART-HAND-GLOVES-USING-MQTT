#define DEBUG
#ifdef DEBUG
#define DEBUG_LN(x) Serial.println(x)
#define DEBUG_NNL(x) Serial.print(x)
#else
#define DEBUG_LN(x) while(0){}
#define DEBUG_NNL(x) while(0){}
#endif