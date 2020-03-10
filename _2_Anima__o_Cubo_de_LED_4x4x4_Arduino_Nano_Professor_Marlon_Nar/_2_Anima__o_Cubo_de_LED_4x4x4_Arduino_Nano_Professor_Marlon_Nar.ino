
//int Filas[4]={A3,A2,A1,A0}; //initializing and declaring led layers
//int Columnas[16]={13,12,11,10,9,8,7,6,5,4,3,2,1,0,A5,A4}; //initializing and declaring led rows
  
// Initalize our LED columns (positive)
int Columnas[] = {0,1,2,3,4,5,6,7,8,9,10,11,12,13,14,15};

// Initalize the LED layers (ground)
 int Filas[] = {16,17,18,19};

int num;
int vel;
int count;
int layer;

// Setup
void setup(){
  // Set up LED columns as output
  for(int pin = 0; pin < 16 ; pin++ ){
    pinMode(Columnas[pin],OUTPUT);
    digitalWrite(Columnas[pin],LOW);
  }
  // Set up LED Layers as output
  for(int layer = 0; layer < 4; layer++){
    pinMode(Filas[layer], OUTPUT);
    digitalWrite(Filas[layer], LOW);
    //delay(100);
  }
}
// The Loop
void loop(){

  /////////////////////////////////////////////////////////////////////////////////
  //  This increments the layers from top to bottom
  /////////////////////////////////////////////////////////////////////////////////
  //digitalWrite(Columnas[0],LOW);
  //digitalWrite(Columnas[1],LOW);
  //digitalWrite(Columnas[2],LOW);
  //digitalWrite(Columnas[3],LOW);
  //digitalWrite(Columnas[4],LOW);
  //digitalWrite(Columnas[5],LOW);
  //digitalWrite(Columnas[6],HIGH);
  //digitalWrite(Columnas[7],LOW);
  //digitalWrite(Columnas[8],LOW);
  //digitalWrite(Columnas[9],LOW);
  //digitalWrite(Columnas[10],LOW);
  //digitalWrite(Columnas[11],LOW);
  //digitalWrite(Columnas[12],LOW);
  //digitalWrite(Columnas[13],LOW);
  //digitalWrite(Columnas[14],LOW);
  //digitalWrite(Columnas[15],LOW);
  //digitalWrite(Filas[0],HIGH); 
  //digitalWrite(Filas[1],HIGH); 
  //digitalWrite(Filas[2],HIGH); 
  //digitalWrite(Filas[3],HIGH);
  

//COMBO1
num=1;
  while(num<4){
    for(count=0;count < 4;count++){
    digitalWrite(Filas[count],HIGH);
    }
    for(count=0;count < 16;count++){
    digitalWrite(Columnas[count],HIGH); 
    delay(100);
    }
    for(count=15;count > -1;count--){
    digitalWrite(Columnas[count],LOW); 
    delay(100);
    }
    digitalWrite(Columnas[0],HIGH);
    delay(100);
    for(count=11;count > 0;count--){
    digitalWrite(Columnas[count],HIGH); 
    delay(100);
    }
    digitalWrite(Columnas[12],HIGH);
    delay(100);
    for(count=15;count > 12 ;count--){
    digitalWrite(Columnas[count],HIGH); 
    delay(100);
    }
    //switch case
    if(num<6){
      for(count=13;count < 16 ;count++){
      digitalWrite(Columnas[count],LOW); 
      delay(100);
      }
      digitalWrite(Columnas[12],LOW);
      delay(100);
      for(count=1;count < 12;count++){
      digitalWrite(Columnas[count],LOW); 
      delay(100);
      }
      digitalWrite(Columnas[0],LOW);
      delay(100);
    } 
    else{
      digitalWrite(Columnas[12],LOW);
      delay(100);
      digitalWrite(Columnas[11],LOW);
      delay(100);
      for(count=0;count < 11 ;count++){
      digitalWrite(Columnas[count],LOW); 
      delay(100);
      }
    for(count=15;count > 12 ;count--){
      digitalWrite(Columnas[count],LOW); 
      delay(100);
      }
    }
  num++;
 }
//COMBO2.1
   num=1;
   while(num<5){
     for(count=4;count > -1;count--){
     digitalWrite(Filas[count],LOW);
     //delay(150);
     }
     for(count=0;count < 16;count++){
     digitalWrite(Columnas[count],HIGH); 
     }
     for(count=0;count < 4;count++){
     digitalWrite(Filas[count],HIGH);
     delay(100);
     }
    num++;
  }
  
//COMBO2.2  
   num=1;
   while(num<5){
     for(count=4;count > -1;count--){
     digitalWrite(Filas[count],LOW);
     //delay(150);
     }
     for(count=0;count < 16;count++){
     digitalWrite(Columnas[count],HIGH); 
     }
     for(count=4;count > -1;count--){
     digitalWrite(Filas[count],HIGH);
     delay(100);
     }
    num++;
  }
//COMBO3

   num=1;
   while(num<2){
  for(count=0;count < 16;count++){
     digitalWrite(Columnas[count],LOW); 
     }
     for(count=15;count > -1;count--){
     digitalWrite(Columnas[count],HIGH); 
     delay(100);
     }
     for(count=0;count < 16;count++){
     digitalWrite(Columnas[count],LOW); 
     delay(100);
     }
    num++;
  }

//COMBO4 
    delay(200);
    for(count=0;count < 4;count++){
    digitalWrite(Columnas[count],HIGH); 
    }
    delay(500);
    for(count=6;count < 10;count++){
    digitalWrite(Columnas[count],HIGH); 
    }
    delay(500);
    for(count=0;count < 4;count++){
    digitalWrite(Columnas[count],LOW); 
    }
    delay(500);
    for(count=6;count < 10;count++){
    digitalWrite(Columnas[count],LOW); 
    }
    delay(500);
    digitalWrite(Columnas[9],HIGH);
    digitalWrite(Columnas[10],HIGH);
    digitalWrite(Columnas[11],HIGH);
    digitalWrite(Columnas[0],HIGH);
    delay(500);
    for(count=3;count < 7;count++){
    digitalWrite(Columnas[count],HIGH);
    }
    delay(500);
    digitalWrite(Columnas[9],LOW);
    digitalWrite(Columnas[10],LOW);
    digitalWrite(Columnas[11],LOW);
    digitalWrite(Columnas[0],LOW);
    delay(500);
    for(count=3;count < 7;count++){
    digitalWrite(Columnas[count],LOW);
    }
   delay(500);
//COMBO5.1
num=1;
  while(num<7){
    delay(200);
    for(count=0;count < 4;count++){
    digitalWrite(Columnas[count],HIGH);
    }
    vel=200/num;
    delay(vel);
    for(count=0;count < 4;count++){
    digitalWrite(Columnas[count],LOW); 
    }
    delay(vel);
    digitalWrite(Columnas[4],HIGH);
    digitalWrite(Columnas[11],HIGH);
    digitalWrite(Columnas[12],HIGH);
    digitalWrite(Columnas[13],HIGH);
    delay(vel);
    digitalWrite(Columnas[4],LOW);
    digitalWrite(Columnas[11],LOW);
    digitalWrite(Columnas[12],LOW);
    digitalWrite(Columnas[13],LOW);
    delay(vel);
    digitalWrite(Columnas[5],HIGH);
    digitalWrite(Columnas[10],HIGH);
    digitalWrite(Columnas[14],HIGH);
    digitalWrite(Columnas[15],HIGH);
    delay(vel);
    digitalWrite(Columnas[5],LOW);
    digitalWrite(Columnas[10],LOW);
    digitalWrite(Columnas[14],LOW);
    digitalWrite(Columnas[15],LOW);
    delay(vel);
    for(count=6;count < 10;count++){
    digitalWrite(Columnas[count],HIGH); 
    }
    delay(vel);
    for(count=6;count < 10;count++){
    digitalWrite(Columnas[count],LOW); 
    }
    delay(200);
  num++;
}

//COMBO5.2
num=1;
  while(num<7){
    delay(200);
    for(count=3;count < 7;count++){
    digitalWrite(Columnas[count],HIGH);
    }
    vel=200/num;
    delay(vel);
    for(count=3;count < 7;count++){
    digitalWrite(Columnas[count],LOW); 
    }
    delay(vel);
    digitalWrite(Columnas[2],HIGH);
    digitalWrite(Columnas[13],HIGH);
    digitalWrite(Columnas[14],HIGH);
    digitalWrite(Columnas[7],HIGH);
    delay(vel);
    digitalWrite(Columnas[2],LOW);
    digitalWrite(Columnas[13],LOW);
    digitalWrite(Columnas[14],LOW);
    digitalWrite(Columnas[7],LOW);
    delay(vel);
    digitalWrite(Columnas[8],HIGH);
    digitalWrite(Columnas[15],HIGH);
    digitalWrite(Columnas[12],HIGH);
    digitalWrite(Columnas[1],HIGH);
    delay(vel);
    digitalWrite(Columnas[8],LOW);
    digitalWrite(Columnas[15],LOW);
    digitalWrite(Columnas[12],LOW);
    digitalWrite(Columnas[1],LOW);
    delay(vel);
    for(count=9;count < 12;count++){
    digitalWrite(Columnas[count],HIGH);
    }
    digitalWrite(Columnas[0],HIGH);
    delay(vel);
    for(count=9;count < 12;count++){
    digitalWrite(Columnas[count],LOW); 
    }
    digitalWrite(Columnas[0],LOW);
    delay(200);
  num++;
}
//COMBO6
num=1;
  while(num<3){
    delay(100);
    digitalWrite(Columnas[0],HIGH);
    delay(100);
    digitalWrite(Columnas[11],HIGH);
    digitalWrite(Columnas[1],HIGH);
    delay(100);
    digitalWrite(Columnas[10],HIGH);
    digitalWrite(Columnas[12],HIGH);
    digitalWrite(Columnas[2],HIGH);
    delay(100);
    digitalWrite(Columnas[9],HIGH);
    digitalWrite(Columnas[15],HIGH);
    digitalWrite(Columnas[13],HIGH);
    digitalWrite(Columnas[3],HIGH);
    delay(100);
    digitalWrite(Columnas[8],HIGH);
    digitalWrite(Columnas[14],HIGH);
    digitalWrite(Columnas[4],HIGH);
    delay(100);
    digitalWrite(Columnas[7],HIGH);
    digitalWrite(Columnas[5],HIGH);
    delay(100);
    digitalWrite(Columnas[6],HIGH);
    delay(100);
    digitalWrite(Columnas[6],LOW);
    delay(100);
    digitalWrite(Columnas[7],LOW);
    digitalWrite(Columnas[5],LOW);
    delay(100);
    digitalWrite(Columnas[8],LOW);
    digitalWrite(Columnas[14],LOW);
    digitalWrite(Columnas[4],LOW);
    delay(100);
    digitalWrite(Columnas[9],LOW);
    digitalWrite(Columnas[15],LOW);
    digitalWrite(Columnas[13],LOW);
    digitalWrite(Columnas[3],LOW);
    delay(100);
    digitalWrite(Columnas[10],LOW);
    digitalWrite(Columnas[12],LOW);
    digitalWrite(Columnas[2],LOW);
    delay(100);
    digitalWrite(Columnas[11],LOW);
    digitalWrite(Columnas[1],LOW);
    delay(100);
    digitalWrite(Columnas[0],LOW);
    delay(100);
    num++;
  }
//COMBO6
num=1;
  while(num<3){
    delay(100);
    digitalWrite(Columnas[9],HIGH);
    delay(100);
    digitalWrite(Columnas[8],HIGH);
    digitalWrite(Columnas[10],HIGH);
    delay(vel);
    digitalWrite(Columnas[7],HIGH);
    digitalWrite(Columnas[15],HIGH);
    digitalWrite(Columnas[11],HIGH);
    delay(100);
    digitalWrite(Columnas[6],HIGH);
    digitalWrite(Columnas[14],HIGH);
    digitalWrite(Columnas[12],HIGH);
    digitalWrite(Columnas[0],HIGH);
    delay(100);
    digitalWrite(Columnas[5],HIGH);
    digitalWrite(Columnas[13],HIGH);
    digitalWrite(Columnas[1],HIGH);
    delay(100);
    digitalWrite(Columnas[4],HIGH);
    digitalWrite(Columnas[2],HIGH);
    delay(100);
    digitalWrite(Columnas[3],HIGH);
    delay(100);
    digitalWrite(Columnas[3],LOW);
    delay(100);
    digitalWrite(Columnas[4],LOW);
    digitalWrite(Columnas[2],LOW);
    delay(100);
    digitalWrite(Columnas[5],LOW);
    digitalWrite(Columnas[13],LOW);
    digitalWrite(Columnas[1],LOW);
    delay(100);
    digitalWrite(Columnas[6],LOW);
    digitalWrite(Columnas[14],LOW);
    digitalWrite(Columnas[12],LOW);
    digitalWrite(Columnas[0],LOW);
    delay(100);
    digitalWrite(Columnas[7],LOW);
    digitalWrite(Columnas[15],LOW);
    digitalWrite(Columnas[11],LOW);
    delay(100);
    digitalWrite(Columnas[8],LOW);
    digitalWrite(Columnas[10],LOW);
    delay(100);
    digitalWrite(Columnas[9],LOW);
    delay(100);
    num++;
  }  

//COMBO7
num=1;
  while(num<8){
    for(count=0;count < 4;count++){
    digitalWrite(Filas[count],LOW);
    }
    for(count=0;count < 16;count++){
    digitalWrite(Columnas[count],HIGH); 
    }
    delay(250);
    digitalWrite(Filas[3],HIGH);
    delay(250);
    digitalWrite(Filas[3],LOW);
    digitalWrite(Filas[2],HIGH);
    delay(150);
    digitalWrite(Filas[2],LOW);
    digitalWrite(Filas[1],HIGH);
    delay(250);
    digitalWrite(Filas[1],LOW);
    digitalWrite(Filas[0],HIGH);
    delay(250);
    digitalWrite(Filas[0],LOW);
    delay(250);
    num++;
    }
for(count=0;count < 16;count++){
digitalWrite(Columnas[count],LOW); 
}
for(count=0;count < 4;count++){
digitalWrite(Filas[count],HIGH);
}
    
//COMBO8
num=1;
  while(num<4){
    delay(200);
    for(count=0;count < 4;count++){
    digitalWrite(Columnas[count],HIGH);
    }
    delay(500);
    for(count=0;count < 4;count++){
    digitalWrite(Columnas[count],LOW); 
    }
    delay(20);
    digitalWrite(Columnas[4],HIGH);
    digitalWrite(Columnas[11],HIGH);
    digitalWrite(Columnas[12],HIGH);
    digitalWrite(Columnas[13],HIGH);
    delay(20);
    digitalWrite(Columnas[4],LOW);
    digitalWrite(Columnas[11],LOW);
    digitalWrite(Columnas[12],LOW);
    digitalWrite(Columnas[13],LOW);
    delay(20);
    digitalWrite(Columnas[5],HIGH);
    digitalWrite(Columnas[10],HIGH);
    digitalWrite(Columnas[14],HIGH);
    digitalWrite(Columnas[15],HIGH);
    delay(20);
    digitalWrite(Columnas[5],LOW);
    digitalWrite(Columnas[10],LOW);
    digitalWrite(Columnas[14],LOW);
    digitalWrite(Columnas[15],LOW);
    delay(20);
    for(count=6;count < 10;count++){
    digitalWrite(Columnas[count],HIGH); 
    }
    delay(500);
    for(count=6;count < 10;count++){
    digitalWrite(Columnas[count],LOW); 
    }
    delay(200);
    num++;
    }
    
    //COMBO5.2
num=1;
  while(num<4){
    delay(200);
    for(count=3;count < 7;count++){
    digitalWrite(Columnas[count],HIGH);
    }
    delay(500);
    for(count=3;count < 7;count++){
    digitalWrite(Columnas[count],LOW); 
    }
    delay(20);
    digitalWrite(Columnas[2],HIGH);
    digitalWrite(Columnas[13],HIGH);
    digitalWrite(Columnas[14],HIGH);
    digitalWrite(Columnas[7],HIGH);
    delay(20);
    digitalWrite(Columnas[2],LOW);
    digitalWrite(Columnas[13],LOW);
    digitalWrite(Columnas[14],LOW);
    digitalWrite(Columnas[7],LOW);
    delay(20);
    digitalWrite(Columnas[8],HIGH);
    digitalWrite(Columnas[15],HIGH);
    digitalWrite(Columnas[12],HIGH);
    digitalWrite(Columnas[1],HIGH);
    delay(20);
    digitalWrite(Columnas[8],LOW);
    digitalWrite(Columnas[15],LOW);
    digitalWrite(Columnas[12],LOW);
    digitalWrite(Columnas[1],LOW);
    delay(20);
    for(count=9;count < 12;count++){
    digitalWrite(Columnas[count],HIGH);
    }
    digitalWrite(Columnas[0],HIGH);
    delay(500);
    for(count=9;count < 12;count++){
    digitalWrite(Columnas[count],LOW); 
    }
    digitalWrite(Columnas[0],LOW);
    delay(200);
  num++;
}

//COMBO7
   num=1;
   while(num<5){
       delay(400);
       for(count=0;count < 12;count++){
       digitalWrite(Columnas[count],HIGH);
       }
       delay(300);
       for(count=0;count < 12;count++){
       digitalWrite(Columnas[count],LOW);
       }
       delay(300);
       for(count=12;count < 16;count++){
       digitalWrite(Columnas[count],HIGH); 
       }
       delay(300);
       for(count=12;count < 16;count++){
       digitalWrite(Columnas[count],LOW);
       }
    num++;
    delay(500);
   }
}
