#include <stdio.h>
#include <stdlib.h>
#define MAX_HEIGHT 41

struct box
{
	int length,width,height;
    /**
	* Define three fields of type int: length, width and height
	*/
};

typedef struct box box; /*keyword used to provide meaningful names to already existing 
                        variables*/

int get_volume(box b) {
	int volume;
    volume=(b.length)*(b.width)*(b.height);
    return volume;
    /**
	* Return the volume of the box
	*/
}

int is_lower_than_max_height(box b) {
	if(b.height<MAX_HEIGHT)
        return 1;
    else
        return 0;
    /**
	* Return 1 if the box's height is lower than MAX_HEIGHT and 0 otherwise
	*/
}

int main()
{
	int n;
	scanf("%d", &n);
	box *boxes = malloc(n * sizeof(box)); //declaring an array with a pointer that points to data type box. the array has 'n' variables of type
	for (int i = 0; i < n; i++) {
		scanf("%d%d%d", &boxes[i].length, &boxes[i].width, &boxes[i].height);
	}
	for (int i = 0; i < n; i++) {
		if (is_lower_than_max_height(boxes[i])) {
			printf("%d\n", get_volume(boxes[i]));
		}
	}
	return 0;
}