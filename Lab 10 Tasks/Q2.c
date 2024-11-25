#include <stdio.h>
#include <math.h>

struct point
{
    float x;
    float y;
};

float distance(struct point a, struct point b)
{
    float distance_btw_points;
    distance_btw_points = sqrt(((a.x - b.x) * (a.x - b.x)) + ((a.y - b.y) * (a.y - b.y)));
    
    printf("The distance between the two points is %f", distance_btw_points);
    return distance_btw_points;
}

int rectangle(struct point p, struct point sl, struct point sr, struct point wl, struct point wr) 
{
    if (p.x >= sl.x && p.x <= sr.x) 
    {
        if (p.y <= sl.y && p.y >= wl.y) 
        {
            printf("\nWithin the rectangular boundary!!\n");
            return 1;
        }
    } 
    
    else 
    {
        printf("\nNot within the rectangular boundary!!\n");
    }
    
    return 0;
}

int main() {
    
    struct point a = {4,4};
    struct point b = {3,3};
    distance(a, b);
    
    struct point sl={2,5};
    struct point sr={5,5};
    struct point wr={5,2};
    struct point wl={2,2};
    
    rectangle(a, sl, sr, wl, wr);
    
}
    return 0;
}

int main(){
    struct Point A={4,4};
    struct Point B={3,3};
    distance(A, B);
    struct Point sl={2,5};
    struct Point sr={5,5};
    struct Point wr={5,2};
    struct Point wl={2,2};
    rectangle(A,sl,sr,wl,wr);
    
}
