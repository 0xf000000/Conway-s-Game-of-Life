#include "GameOfLive.h"

char MAP[WIDTH * HEIGHT];
char NEWMAP[WIDTH * HEIGHT];

void printScreen(char *map)
{
   Clear; F;
   int k = 0;
   for (int i = 0; i < HEIGHT; i++)
   {

      for (int j = 0; j < WIDTH; j++)
      {

         putchar(MAP[k++]);
      }

      putchar('\n');
   }
}

/**
    +
  + +
   ++
*/

int getNabers(int index)
{
   int nabers = 0;
   int above = index - WIDTH;
   int under = index + WIDTH;
   // LEFT
   if (index != 0 && MAP[index - 1] == CELL)
   {
      nabers++;
   }
   // RIGTH
   if (index < WIDTH * HEIGHT && MAP[index + 1] == CELL)
   {
      nabers++;
   }

   // ABOVE
   if (above > 0 && MAP[above] == CELL)
   {
      nabers++;
   }

   // ABOVE LEFT
   if (above - 1 > 0 && MAP[above - 1] == CELL)
   {
      nabers++;
   }

   // ABOVE RIGTH

   if (above + 1 > 0 && MAP[above + 1] == CELL)
   {
      nabers++;
   }

   // UNDER

   if (under < WIDTH * HEIGHT && MAP[under] == CELL)
   {

      nabers++;
   }

   // UNDER LEFT
   if (under - 1 < WIDTH * HEIGHT && MAP[under - 1] == CELL)
   {

      nabers++;
   }

   // UNDER RIGHT

   if (under + 1 < WIDTH * HEIGHT && MAP[under + 1] == CELL)
   {

      nabers++;
   }

   return nabers;
}

/**
 *  Any live cell with fewer than two live neighbours dies, as if by underpopulation.
    Any live cell with two or three live neighbours lives on to the next generation.
    Any live cell with more than three live neighbours dies, as if by overpopulation.
    Any dead cell with exactly three live neighbours becomes a live cell, as if by reproduction.
 *
 */

void applyRules(void)
{

   memcpy(&NEWMAP, &MAP, sizeof(MAP));
   for (int i = 0; i < WIDTH * HEIGHT; i++)
   {

      int nabers = getNabers(i);

      // dies
      if (MAP[i] == CELL && nabers < 2)
      {
         NEWMAP[i] = ' ';
      }
      else

          if (MAP[i] == CELL && (nabers == 2 || nabers == 3))
      {
         // MAP[i] = CELL;
      }
      else
         // dies
         if (MAP[i] == CELL && nabers > 3)
         {
            NEWMAP[i] = ' ';
         }
         else

             if (nabers == 3)
         {
            NEWMAP[i] = CELL;
         }
   }

   memcpy(&MAP, NEWMAP, sizeof(NEWMAP));
}

void loop(void)
{

   printScreen(&MAP);

   applyRules();

   usleep(100000);
}

void setupMap(void){

   memset(&MAP, ' ', sizeof(MAP));
   /*
starting pattern:

    +
  + +
   ++
*/
   MAP[(((HEIGHT * WIDTH / 2)) - (WIDTH)) + 3] = CELL;
   MAP[(((HEIGHT * WIDTH / 2)) - (WIDTH)) + 2] = CELL;
   MAP[(((HEIGHT * WIDTH / 2)) - (WIDTH * 2)) + 1] = CELL;
   MAP[(((HEIGHT * WIDTH / 2)) - (WIDTH * 2)) + 3] = CELL;
   MAP[(((HEIGHT * WIDTH / 2)) - (WIDTH * 3)) + 3] = CELL;

}



int main(int argc, char **argv)
{
   

   while (running)
   {

      loop();
   }

   return EXIT_SUCCESS;
}
