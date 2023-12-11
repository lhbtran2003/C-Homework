#include<stdio.h>
#include<math.h>
int main() {
    float a, b, c, x, d,e, f;
    printf("Nhap vao lan luot a, b, c: ",a, b, c);
    //a, b, c la gia tri nhap vao, d: delta,/ e, f la  gia tri 2 nghiem phan biet
    scanf("%f, %f, %f\n", &a, &b, &c);
    if (a == 0)
    {
        if (b == 0)
        {
            if (c == 0)
            {
                printf("Phuong trinh vo so nghiem.");
            } else
            {
                printf("Phuong trinh vo nghiem.");
            }
        } else
        {
            printf("Phuong trinh co nghiem duy nhat: %f", -b/c);
        }
    } else
    {
        d = b*b - 4*a*c;
        if (d < 0) { printf("Phuong trinh vo nghiem.");}
        else if (d > 0)
        {
            printf("Phuong trinh co 2 nghiem kep: %f",-b/(2*a) );
        }

        else if (d < 0)
        {
            e= (-b+sqrt(d))/(2*a) ;
            f= (-b-sqrt(d))/(2*a) ;
            printf("Phuong trinh co 2 nghiem phan biet: %f, %f" , e, d);
        }

    }


}