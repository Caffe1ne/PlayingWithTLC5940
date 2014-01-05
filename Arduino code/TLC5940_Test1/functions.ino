
/**************************
 * RGB FUNCTION SELECTION *
 **************************/
 
/* Uncomment the function you want to use and comment out the other two */
        /***** BEGIN PLAIN CUTOFF FUNCTION *****/
        /***** END PLAIN CUTOFF FUNCTION *****/

        /***** BEGIN CUTOFF SINOID FUNCTION ****
        /***** END CUTOFF SINOID FUNCTION *****/


// NJSG        /***** BEGIN SINOID FUNCTION *****/
        // This is a medicore function which is rather obsolete but it's what I've got currently
        // These functions are called using the iteration of the control function/loop and these control the value based on that
        // They currently take a float which is supposed to be in the range 0-360 (following nice circular sinoids)
        int sinRed(float x){
          return (MAX_PWM_VALUE/2 * sin((x * pi) / 180 + offsetRed) + MAX_PWM_VALUE/2);
        }
        int sinGreen(float x){
          return (MAX_PWM_VALUE/2 * sin((x * pi) / 180 + offsetGreen) + MAX_PWM_VALUE/2);
        }
        int sinBlue(float x){
          return (MAX_PWM_VALUE/2 * sin((x * pi) / 180 + offsetBlue) + MAX_PWM_VALUE/2);
        }
        /***** END SINOID FUNCTION *****/
