#include <stdio.h>
#define PI 3.14159
#define AREA_OF_CIRCLE(r) (PI*r*r)
#define SURFACE_AREA_OF_CYLINDER(r,h) (2*PI*r*(r+h))
int main(){
float r,h,surface_area,area;
printf("Enter the radius and height  of cylinder and circle :");
scanf(" %f %f",&r,&h);
area=AREA_OF_CIRCLE(r);
printf("The area of the circle is:%f",area);
surface_area=SURFACE_AREA_OF_CYLINDER(r,h);
printf("The surface area of the cylinder is:%f",surface_area);
return 0;
}

