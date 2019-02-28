#include <kipr/botball.h>

int main()
{
    int dist1 = 3058;
    int dist2 = 2781;
    int dist3 = 600;
    int dist4 = 1667;
   	
    int arm= 0; 
    int claw=1; 
    
    int up = 300;
    int down = 1271; 
    
    int open = 1500;
    int close= 857; 
    
    wait_for_light(4);
    enable_servos();
    set_servo_position (arm, up);
    msleep (1500);
    set_servo_position (claw, open);
    set_servo_position (arm, down);
    
    cmpc(0);
    while (gmpc (0) < dist1)
    {
        motor (0, 48);
        motor (3, 50);
    }
    
    ao();
   
    set_servo_position (claw, close);
    msleep (150); 
    
    
    cmpc(0);
    while (gmpc (0) < dist2)
    {
        motor (0, 48);
        motor (3, 50);
    }
    ao(); 
    
    cmpc(3);
    while (gmpc (3) < dist3)
    {
        motor (0, -48);
        motor (3, 50);
    }
   
    ao();
    cmpc(0);
    while (gmpc (0) < dist4)
    {
        motor (0, 48);
        motor (3, 50);
    }
    
    ao();
  
    set_servo_position  (claw, open);
    msleep (100); 
    disable_servos ();
    
    return 0;
}
