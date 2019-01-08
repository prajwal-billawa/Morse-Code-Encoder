
int delayTime = 2000;
int lbetween = 200;
int hbetween = 700;
char letter[] = {
'A','B','C','D','E','F','G','H','I','J','K','L','M','N','O','P',
'Q','R','S','T','U','V','W','X','Y','Z'
};
const char* value[] = {
"01","1000","1010","100","0","0010","110","0000","00","0111",
"101","0100","11","10","111","0110","1101",
"010","000","1","001","0001","011","1001","1011","1100" 
};

void setup() {
  // put your setup code here, to run once:
  pinMode(LED_BUILTIN,OUTPUT);
  Serial.begin(9600);
  

}


void loop() {
  // put your main code here, to run repeatedly:

  String c = Serial.readString();
  for(int i=0;i<(c.length());i++){
    
    for(int j=0;j<26;j++){
      if(c[i] == letter[j]){  
      
        Serial.println(letter[j]);
        Serial.println(c[i]);
                                         
        char ml[] = {value[j]};
        
        Serial.println(value[j]);  
        
        for(int z=0;z<strlen(value[j]);z++){
          char idk = value[j][z];       
          int x = idk - '0';

          if(x == 0){
            Serial.println("low");
            Serial.println(x);
            digitalWrite(LED_BUILTIN,1);
            delay(lbetween);
            digitalWrite(LED_BUILTIN,0);
            delay(200);
          }
          else if(x == 1){
            Serial.println("high");
            Serial.println(x);
            digitalWrite(LED_BUILTIN,1);
            delay(hbetween);
            digitalWrite(LED_BUILTIN,0);
            delay(200);
          }
          
         
        }
        delay(delayTime);
      }
      
      else{continue;}
      
      }
   if(c[i] == ' '){
            Serial.println("GAP!!!!!!!!!!!!!!!!!!!!!!!!!!!!!");
            delay(delayTime*2.5);
      }
  }
}  

  
  
