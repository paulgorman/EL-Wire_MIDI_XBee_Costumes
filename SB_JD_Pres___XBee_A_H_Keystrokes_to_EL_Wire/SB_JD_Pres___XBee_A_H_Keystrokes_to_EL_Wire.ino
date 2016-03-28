/* 
 // ===== EL Wire Dress =====
 //  Presence, Joey Doucette, Steve Beyer
 //  20120203
 //  tech@sbeyer.com
 */

#include <EL_Escudo.h>
//The EL_Escudo library uses letters A-H to reference each EL string.
//Each EL string output has a corresponding label on the EL Escudo shield.

String inputString = "";         // a string to hold incoming data
boolean stringComplete = false;  // whether the string is complete
boolean channelA = false;
boolean channelB = false;
boolean channelC = false;
boolean channelD = false;
boolean channelE = false;
boolean channelF = false;
boolean channelG = false;
boolean channelH = false;


void setup() {
  Serial.begin(57600);
  pinMode(10, OUTPUT);
  blinkShit();
  EL.all_off();
}

void loop() {
  if (stringComplete) {
    Serial.println(inputString); 
    digitalWrite(10, HIGH);
    delay(400);
    digitalWrite(10, LOW);
    // clear the string:
    inputString = "";
    stringComplete = false;
  }
  if (channelA) { 
    EL.on(A); 
  } 
  else { 
    EL.off(A); 
  }
  if (channelB) { 
    EL.on(B); 
  } 
  else { 
    EL.off(B); 
  }
  if (channelC) { 
    EL.on(C); 
  } 
  else { 
    EL.off(C); 
  }
  if (channelD) { 
    EL.on(D); 
  } 
  else { 
    EL.off(D); 
  }
  if (channelE) { 
    EL.on(E); 
  } 
  else { 
    EL.off(E); 
  }
  if (channelF) { 
    EL.off(7);
  } 
  else { 
    EL.on(7);
  }
  if (channelG) { 
    EL.on(G); 
  } 
  else { 
    EL.off(G); 
  }
  if (channelH) { 
    EL.on(H); 
  } 
  else { 
    EL.off(H); 
  }  
}

/*
  SerialEvent occurs whenever a new data comes in the
 hardware serial RX.  This routine is run between each
 time loop() runs, so using delay inside loop can delay
 response.  Multiple bytes of data may be available.
 */
void serialEvent() {
  while (Serial.available()) {
    // get the new byte:
    char inChar = (char)Serial.read(); 
    // add it to the inputString:
    inputString += inChar;
    // if the incoming character is a newline, set a flag
    // so the main loop can do something about it:
    switch (inChar) {
    case 'a':
      if (channelA) { 
        channelA = false; 
      } 
      else { 
        channelA = true; 
      }
      break;
    case 'b':
      if (channelB) { 
        channelB = false; 
      } 
      else { 
        channelB = true; 
      }
      break;
    case 'c':
      if (channelC) { 
        channelC = false; 
      } 
      else { 
        channelC = true; 
      }
      break;
    case 'd':
      if (channelD) { 
        channelD = false; 
      } 
      else { 
        channelD = true; 
      }
      break;
    case 'e':
      if (channelE) { 
        channelE = false; 
      } 
      else { 
        channelE = true; 
      }
      break;
    case 'f':
      if (channelF) { 
        channelF = false; 
      } 
      else { 
        channelF = true; 
      }
      break;
    case 'g':
      if (channelG) { 
        channelG = false; 
      } 
      else { 
        channelG = true; 
      }
      break;
    case 'h':
      if (channelH) { 
        channelH = false; 
      } 
      else { 
        channelH = true; 
      }
      break;
    case 'z':
      channelA = false; 
      channelB = false; 
      channelC = false; 
      channelD = false; 
      channelE = false; 
      channelF = false; 
      channelG = false;
      channelH = false;
      EL.all_off();
      digitalWrite(10, LOW);
      break;
    case 'y':
      channelA = false; 
      channelB = false; 
      channelC = false; 
      channelD = false; 
      channelE = false; 
      channelF = false; 
      channelG = false;      
      channelH = false;
      EL.all_on();
      digitalWrite(10, HIGH);
      break;
    }
    if (inChar == 'x') {
      stringComplete = true;
    } 
  }
}

void blinkShit() {
  digitalWrite(10, HIGH);
  delay(100);
  digitalWrite(10, LOW);
  delay(100);
  digitalWrite(10, HIGH);
  delay(100);
  digitalWrite(10, LOW);
  delay(100);
  digitalWrite(10, HIGH);
  delay(100);
  digitalWrite(10, LOW);
  delay(100);

}



