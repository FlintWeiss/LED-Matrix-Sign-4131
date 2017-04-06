
#include <Adafruit_NeoMatrix.h>
#include <gamma.h>

#include <Adafruit_NeoPixel.h>
#include <Adafruit_GFX.h>
#include <gfxfont.h>

#ifndef PSTR
 #define PSTR // Make Arduino Due happy
#endif

#include "ColorDefinitions.h"
#include "SpriteBitmaps.h"

/*-------------------------------------------------------------------------

  --------------------------------------------------------------------*/


#define PIXEL_COUNT 256

#define NUM_COL 32
#define NUM_ROW 8

// IMPORTANT: Set pixel PIN and TYPE
#define PIXEL_PIN 6
#define PIXEL_TYPE NEO_GRB + NEO_KHZ800

// Parameter 1 = number of pixels in strip
// Parameter 2 = Arduino pin number (most are valid)
// Parameter 3 = pixel type flags, add together as needed:
//   NEO_KHZ800  800 KHz bitstream (most NeoPixel products w/WS2812 LEDs)
//   NEO_KHZ400  400 KHz (classic 'v1' (not v2) FLORA pixels, WS2811 drivers)
//   NEO_GRB     Pixels are wired for GRB bitstream (most NeoPixel products)
//   NEO_RGB     Pixels are wired for RGB bitstream (v1 FLORA pixels, not v2)


  // create a reference to the whole strand, including overflow pixels not used in the matrix
//  Adafruit_NeoPixel wholeStrip = Adafruit_NeoPixel(PIXEL_COUNT, PIXEL_PIN, PIXEL_TYPE);


// MATRIX DECLARATION:
// Parameter 1 = width of EACH NEOPIXEL MATRIX (not total display)
// Parameter 2 = height of each matrix
// Parameter 3 = number of matrices arranged horizontally
// Parameter 4 = number of matrices arranged vertically
// Parameter 5 = pin number (most are valid)
// Parameter 6 = matrix layout flags, add together as needed:
//   NEO_MATRIX_TOP, NEO_MATRIX_BOTTOM, NEO_MATRIX_LEFT, NEO_MATRIX_RIGHT:
//     Position of the FIRST LED in the FIRST MATRIX; pick two, e.g.
//     NEO_MATRIX_TOP + NEO_MATRIX_LEFT for the top-left corner.
//   NEO_MATRIX_ROWS, NEO_MATRIX_COLUMNS: LEDs WITHIN EACH MATRIX are
//     arranged in horizontal rows or in vertical columns, respectively;
//     pick one or the other.
//   NEO_MATRIX_PROGRESSIVE, NEO_MATRIX_ZIGZAG: all rows/columns WITHIN
//     EACH MATRIX proceed in the same order, or alternate lines reverse
//     direction; pick one.
//   NEO_TILE_TOP, NEO_TILE_BOTTOM, NEO_TILE_LEFT, NEO_TILE_RIGHT:
//     Position of the FIRST MATRIX (tile) in the OVERALL DISPLAY; pick
//     two, e.g. NEO_TILE_TOP + NEO_TILE_LEFT for the top-left corner.
//   NEO_TILE_ROWS, NEO_TILE_COLUMNS: the matrices in the OVERALL DISPLAY
//     are arranged in horizontal rows or in vertical columns, respectively;
//     pick one or the other.
//   NEO_TILE_PROGRESSIVE, NEO_TILE_ZIGZAG: the ROWS/COLUMS OF MATRICES
//     (tiles) in the OVERALL DISPLAY proceed in the same order for every
//     line, or alternate lines reverse direction; pick one.  When using
//     zig-zag order, the orientation of the matrices in alternate rows
//     will be rotated 180 degrees (this is normal -- simplifies wiring).
//   See example below for these values in action.
// Parameter 7 = pixel type flags: for the Photon/Electron library, we have
//   to pick pre-consolidated values and we can't use the regular Adafruit
//   library approach of just adding flag values together :( 

// Example with one 22x9 matrix.  
// The first pixel within is at the top left.  The matrices use zig-zag line ordering.
// There's only one matrix here, so it doesn't matter if we declare it in row
// or column order.  

Adafruit_NeoMatrix matrix = Adafruit_NeoMatrix(NUM_COL, NUM_ROW, 1, 1, PIXEL_PIN,
  NEO_TILE_TOP   + NEO_TILE_LEFT   + NEO_TILE_COLUMNS   + NEO_TILE_ZIGZAG +
  NEO_MATRIX_TOP + NEO_MATRIX_LEFT + NEO_MATRIX_COLUMNS + NEO_MATRIX_ZIGZAG,
  PIXEL_TYPE);

String webText = " Liberty Robotics   FIRST  FRC  4131  The  Iron  Patriots  from  Liberty High School in Renton WA   Honk if you love robots!    ";

//-------------------------------------------------------------------------------
void setup() {
   // turn off all the pixels in the strip, even the overflow pixels that 
   // aren't used in the matrix. Sometimes they turn on solid white

   pinMode(13, OUTPUT);  // for the onboard LED, in case we need it for debugging
   
//   wholeStrip.begin();    //wholeStrip.show(); 

   //Serial.begin(9600);
   matrix.begin();
   matrix.setTextWrap(false);
   matrix.setBrightness(50); // was 150
   matrix.setTextColor(matrix.Color(0,255,0));
  

} // end setup



//--------------------------------------------------------------------------------
void loop() {

   blinkLED(3);

//   digitalWrite(13, HIGH);
   lightsOff();
  
//   testMatrixWipe(1); lightsOff(); delay(500);

/*
   // fix the screen with purple 
   matrix.fillRect(0, 0, NUM_COL, NUM_ROW, color(PURPLE)); matrix.show();
   delay(1000); 
    
   // draw a box in yellow 
   // drawRect parameters: x,y starting cooridnates, then width and height, then color
   matrix.drawRect(0, 0, NUM_COL, NUM_ROW, color(YELLOW)); matrix.show();
   delay(1000); 
       
   // draw an 'X' in red 
   // Use the number of rows to force a "square X"
   int xHeight = NUM_ROW - 1;
   int xWidth  = NUM_ROW - 1;
   int xStart  = 0;
   matrix.drawLine(xStart, 0, xWidth, xHeight, matrix.Color(2550, 0, 0)); matrix.drawLine(xHeight, 0, xStart, xWidth, matrix.Color(255, 0, 0));
   // Put another X next to the previous one
   
   xStart  = xWidth + 1;
   matrix.drawLine(xStart, 0, xStart+xWidth, xHeight, matrix.Color(0, 255, 0)); matrix.drawLine(xStart+xWidth, 0, xStart, xHeight, matrix.Color(0, 255, 0)); 
   matrix.show();

   xStart  = xStart + xWidth + 1;
   matrix.drawLine(xStart, 0, xStart+xWidth, xHeight, matrix.Color(0, 0, 255)); matrix.drawLine(xStart+xWidth, 0, xStart, xHeight, matrix.Color(0, 0, 255)); 
   matrix.show();
   
   delay(1000); 
*/
//   lightsOff(); delay(500); 

   scrollText("Liberty Robotics  ");
   alderaan(); lightsOff(); delay(500); 
    
   //rainbowCycle(1); lightsOff(); delay(250);

   scrollText("FIRST   Robotics  FRC  Team  4131   ");      
   pacman(); lightsOff(); delay(250);
/*   
   // Draw a bunch of rectangles "going down"
   matrix.drawRect(0, 0, NUM_COL,   NUM_ROW,   matrix.Color(255, 0, 0)); matrix.show(); delay(500); 
   matrix.drawRect(1, 1, NUM_COL-2, NUM_ROW-2, matrix.Color(0, 255, 0)); matrix.show(); delay(500); 
   matrix.drawRect(2, 2, NUM_COL-4, NUM_ROW-4, matrix.Color(0, 0, 255)); matrix.show(); delay(500); 
   matrix.drawRect(3, 3, NUM_COL-6, NUM_ROW-6, matrix.Color(128, 128, 128)); matrix.show(); delay(500); 
  
   // black out the dispaly similarly
   matrix.drawRect(3, 3, NUM_COL-6, NUM_ROW-6, matrix.Color(0, 0, 0)); matrix.show(); delay(500); 
   matrix.drawRect(2, 2, NUM_COL-4, NUM_ROW-4, matrix.Color(0, 0, 0)); matrix.show(); delay(500); 
   matrix.drawRect(1, 1, NUM_COL-2, NUM_ROW-2, matrix.Color(0, 0, 0)); matrix.show(); delay(500); 
   matrix.drawRect(0, 0, NUM_COL,   NUM_ROW, matrix.Color(0, 0, 0)); matrix.show(); delay(500); 
*/
   scrollText("The  Iron  Patriots  from  Liberty High School in Renton WA    ");
   boxAnimation(5); lightsOff(); delay(250);

/*
   colorWipe(wholeStrip.Color(255, 0, 0), 3, 1); // Red
   colorWipe(wholeStrip.Color(0, 255, 0), 3, 0); // Green
   colorWipe(wholeStrip.Color(0, 0, 255), 3, 1); // Blue

   // Send a theater pixel chase in...
   theaterChase(wholeStrip.Color(127, 127, 127), 50); // White
   theaterChase(wholeStrip.Color(127, 0, 0), 50); // Red
   theaterChase(wholeStrip.Color(0, 0, 127), 50); // Blue

   theaterChaseRainbow(50); lightsOff(); delay(500);
*/
   scrollText("HONK! If you LOVE Robots!!!    ");

    delay(200);
} // end loop

/*==========================================================================
  alderaan: death start blowing up alderaan animation without sprites
  ==========================================================================
*/  
void alderaan(){

   int deathStarX = 2;
   int deathStarY = 5;

   // fill a green circle for Alderaan
   matrix.fillCircle(NUM_COL-4, 3, 3, color(GREEN)); matrix.show(); delay(3000);
   
   // draw the death star amd animate it on screen
   for(int i=deathStarX-2; i<=deathStarX; i++) {
      // clear the previous death star; this is backwards but leaves us in a good state
      matrix.drawCircle(i-1,deathStarY,2, color(BLACK)); 
      matrix.drawPixel(i,deathStarY-1, color(BLACK));
      
      // draw the next iteration
      matrix.drawCircle(i,deathStarY,2, color(GRAY)); 
      matrix.drawPixel(i+1,deathStarY-1, color(YELLOW));
      matrix.show(); delay(500); 
   }
   
   delay(1000);
   // draw little yellow highlight lines to show something going on
   matrix.drawPixel(deathStarX+3,deathStarY-2, color(YELLOW)); matrix.show(); delay(50);
   matrix.drawPixel(deathStarX+4,deathStarY-3, color(YELLOW)); matrix.show(); delay(50);
   matrix.drawPixel(deathStarX+3,deathStarY,   color(YELLOW)); matrix.show(); delay(50);
   matrix.drawPixel(deathStarX+4,deathStarY+1, color(YELLOW)); matrix.show(); delay(50);

   // draw the main death ray
   matrix.drawLine(deathStarX+1,deathStarY-1, NUM_COL-4,3, color(RED));
   matrix.show(); delay(200);

   // turn off the highlight lines
   matrix.drawPixel(deathStarX+3,deathStarY-2, color(BLACK)); matrix.show(); delay(20);
   matrix.drawPixel(deathStarX+4,deathStarY-3, color(BLACK)); matrix.show(); delay(20);
   matrix.drawPixel(deathStarX+3,deathStarY,   color(BLACK)); matrix.show(); delay(20);
   matrix.drawPixel(deathStarX+4,deathStarY+1, color(BLACK)); matrix.show(); delay(20);
   delay(500);

   // clear the death ray
   matrix.drawLine(deathStarX+1,deathStarY-1, NUM_COL-4,3, color(BLACK));
   matrix.drawCircle(deathStarX,deathStarY,2, color(GRAY)); 
   matrix.drawPixel(deathStarX+1,deathStarY-1, color(YELLOW));
   matrix.show(); delay(20); 
   
   // blow up sequence
   matrix.drawLine(NUM_COL-4,3, NUM_COL-7,1,color(RED));
   matrix.drawLine(NUM_COL-4,3, NUM_COL,0,color(RED));
   matrix.drawLine(NUM_COL-4,3, NUM_COL-8,NUM_ROW,color(RED));
   matrix.drawLine(NUM_COL-4,3, NUM_COL,NUM_ROW-1,color(RED));
   matrix.show(); delay(20);

   // orange exanding circle part of blowup sequence
   matrix.fillCircle(NUM_COL-4, 3, 1, color(ORANGE)); matrix.show(); delay(500);
   matrix.fillCircle(NUM_COL-4, 3, 2, color(ORANGE)); matrix.show(); delay(500);
   matrix.fillCircle(NUM_COL-4, 3, 3, color(ORANGE)); matrix.show(); delay(500);
   matrix.fillCircle(NUM_COL-4, 3, 2, color(BLACK)); matrix.show(); delay(500);
   matrix.fillCircle(NUM_COL-4, 3, 4, color(ORANGE)); 
   matrix.fillCircle(NUM_COL-4, 3, 3, color(BLACK)); matrix.show(); delay(500);
   matrix.fillCircle(NUM_COL-4, 3, 5, color(ORANGE)); 
   matrix.fillCircle(NUM_COL-4, 3, 4, color(BLACK)); matrix.show(); delay(500);
   matrix.fillCircle(NUM_COL-4, 3, 6, color(ORANGE)); 
   matrix.fillCircle(NUM_COL-4, 3, 6, color(BLACK)); matrix.show(); delay(500);
   
   delay(500);

} // end alderaan



/*==========================================================================
  pacman: creates a pacman animation using matrix.drawBitmap animations
  ==========================================================================
*/  
void pacman(){

  // draw yellow dots for pacman to eat
  for(int i=1; i<NUM_COL; i=i+3) {
     matrix.drawPixel(i,3, color(GRAY));
     matrix.show();
     delay(50);
  }
  delay(1000);
  
  for(int i=0; i<NUM_COL; i=i+3) {
     matrix.drawBitmap(i,0, pacmanOpen, 8, 8, color(YELLOW));  matrix.show();
     delay(30);
     matrix.drawBitmap(i,0, pacmanOpen, 8, 8, color(BLACK));   matrix.show();
     //delay(2);

     matrix.drawBitmap(i,0, pacmanOpen, 8, 8, color(YELLOW));  matrix.show();
     delay(30);
     matrix.drawBitmap(i,0, pacmanOpen, 8, 8, color(BLACK));   matrix.show();
     //delay(2);

     matrix.drawBitmap(i+2,0, pacmanClosed, 8, 8, color(YELLOW)); matrix.show();
     delay(50);
     matrix.drawBitmap(i+2,0, pacmanClosed, 8, 8, color(BLACK));  matrix.show();
     //delay(2);
  }
  
} // end pacman

//==========================================================================
void boxAnimation(int numTimes) {
 
   // try a going through space animation, where the interior most box works its way out to the edge
   for(int i=0; i<numTimes; i++) {
      matrix.drawRect(0, 0, NUM_COL,   NUM_ROW,   color(BLACK));
      matrix.drawRect(3, 3, NUM_COL-6, NUM_ROW-6, color(GRAY)); 
      matrix.show(); delay(100);

      matrix.drawRect(3, 3, NUM_COL-6, NUM_ROW-6, color(BLACK)); 
      matrix.drawRect(2, 2, NUM_COL-4, NUM_ROW-4, color(GRAY));
      matrix.show(); delay(100);

      matrix.drawRect(2, 2, NUM_COL-4, NUM_ROW-4, color(BLACK));
      matrix.drawRect(1, 1, NUM_COL-2, NUM_ROW-2, color(GRAY)); 
      matrix.show(); delay(100);

      matrix.drawRect(1, 1, NUM_COL-2, NUM_ROW-2, color(BLACK)); 
      matrix.drawRect(0, 0, NUM_COL,   NUM_ROW,   color(GRAY));
      matrix.show(); delay(100);
   }

} // end boxAnimation

//==========================================================================
// Scroll text
//==========================================================================
void scrollText(String& text) {
   int w    = matrix.width();
   //String message = "Hello World";

   int len = text.length();
   int iterations = (len+2) * 6; // font is 6 wide x 8 tall

    matrix.fillScreen(0);
    matrix.setCursor(0, 0);
  
  for(int i=0; i<=iterations; i++) {
    //Serial.print("Scroll Text iteration: "); Serial.println(i);
    matrix.fillScreen(0);
    matrix.setCursor(w, 0);
    matrix.print(text);
    --w; // decrement w to scroll to the left

    matrix.show(); delay(20);
  } // end for
  
  
} // end scrollText

/*
//==========================================================================
// rainbow
void rainbow(uint8_t wait) {
  uint16_t i, j;

  Serial.println("-rainbow");
  for(j=0; j<(256); j++) {
    for(i=0; i<wholeStrip.numPixels(); i++) {
      wholeStrip.setPixelColor(i, Wheel((i+j) & 255));
    }
    wholeStrip.show();
    delay(wait);
  }
} // end rainbow

//==========================================================================
// rainbowCycle - makes a rainbow equally distributed throughout the strand
//==========================================================================
void rainbowCycle(uint8_t wait) {
  uint16_t i, j;

  Serial.println("-rainbowCycle");
  for(j=0; j<256*5; j++) { // 5 cycles of all colors on wheel
    for(i=0; i< wholeStrip.numPixels(); i++) {
      wholeStrip.setPixelColor(i, Wheel( ( (i * 256 / wholeStrip.numPixels() ) + j) & 255) );
    }
    wholeStrip.show();
    delay(wait);
  }
} // end rainbowCycle

//==========================================================================
// Theatre-style crawling lights.
void theaterChase(uint32_t c, uint8_t wait) {
  for (int j=0; j<10; j++) {  //do 10 cycles of chasing
    for (int q=0; q < 3; q++) {
      for (int i=0; i < wholeStrip.numPixels(); i=i+3) {
        wholeStrip.setPixelColor(i+q, c);    //turn every third pixel on
      }
      wholeStrip.show();

      delay(wait);

      for (int i=0; i < wholeStrip.numPixels(); i=i+3) {
        wholeStrip.setPixelColor(i+q, 0);        //turn every third pixel off
      }
    } // end q loop
  } // end j loop
}
*/

/*
//==========================================================================
//Theatre-style crawling lights with rainbow effect
void theaterChaseRainbow(uint8_t wait) {
  for (int j=0; j < 256; j=j+3) {     // cycle all 256 colors in the wheel
    for (int q=0; q < 3; q++) {
      for (int i=0; i < wholeStrip.numPixels(); i=i+3) {
        wholeStrip.setPixelColor(i+q, Wheel( (i+j) % 255));    //turn every third pixel on
      }
      wholeStrip.show();

      delay(wait);

      for (int i=0; i < wholeStrip.numPixels(); i=i+3) {
        wholeStrip.setPixelColor(i+q, 0);        //turn every third pixel off
      }
    } // end q loop
  } // end j loop
}
*/

/*==========================================================================
  Fill the dots one after the other with a color
  c - color to fill
  wait - how slow to go
  forward - should we fill from front or from the back
  ==========================================================================
*/
/*
void colorWipe(uint32_t c, uint8_t wait, int forward) {
   if(forward == 1) {
      for(uint16_t i=0; i < wholeStrip.numPixels(); i++) {
         wholeStrip.setPixelColor(i, c);
         wholeStrip.show();
         delay(wait);
      }
   } else {
      for(uint16_t i=wholeStrip.numPixels(); i > 0; i--) {
         wholeStrip.setPixelColor(i, c);
         wholeStrip.show();
         delay(wait);
      
      } // end for
   } // end if
} // end colorWipe
*/

/*===========================================================================
  // figure ou the matrix addressing model
  //Serial.println("left to right, top to bottom wipe");
  // left to right, top to bottom wipe
*/
void testMatrixWipe(int wait){
  int x,y;
  for(y=0; y<NUM_ROW; y++) {
     for(x=0; x<NUM_COL; x++) { 
         matrix.drawPixel(x,y,matrix.Color(0,0,255));   
         matrix.show();
         delay(wait);
     } // end for x
  } // end for y
} // end testMatrixWipe

//===================================================================================
// converts a HEX color into a matrix color. makes color handling easier.
uint16_t color(unsigned long c) {
   byte red = (c & 0xFF0000) >> 16;
   byte green = ( c & 0x00FF00) >> 8;
   byte blue = (c & 0x0000FF);
   return matrix.Color(red, green, blue);
} // end color


//==========================================================================
// Wheel: Input a value 0 to 255 to get a color value.
// The colours are a transition r - g - b - back to r.
//==========================================================================
/*
uint32_t Wheel(byte WheelPos) {
  WheelPos = 255 - WheelPos;
  if(WheelPos < 85) {
    return wholeStrip.Color(255 - WheelPos * 3, 0, WheelPos * 3);
  }
  if(WheelPos < 170) {
    WheelPos -= 85;
    return wholeStrip.Color(0, WheelPos * 3, 255 - WheelPos * 3);
  }
  WheelPos -= 170;
  return wholeStrip.Color(WheelPos * 3, 255 - WheelPos * 3, 0);
} // end Wheel
*/

/*==========================================================================
   turn all the lights off in both buffers
  ==========================================================================
*/
void lightsOff() {
  for(int i=0; i<PIXEL_COUNT; i++) {
//    wholeStrip.setPixelColor(i,wholeStrip.Color(0,0,0));
  }
//  wholeStrip.show();
  matrix.fillScreen(0); matrix.show();
} // end lightsOff;

//==========================================================================
// blink the onboard LED nTimes

void blinkLED(int nTimes) {
  digitalWrite(13, LOW);
  for(int i=0; i<nTimes; i++) {
    digitalWrite(13, HIGH); 
    delay(300);
    digitalWrite(13, LOW);
    delay(300); 
  }
    
} // end blinkLED


