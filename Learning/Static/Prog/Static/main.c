/* How to use static variable */

#include <stdio.h>
#include <stdlib.h>


/* Pham vi funcion nay chi duoc su dung trong file nay */
static void Function_Static(void);

/* Pham vi bien chi duoc su dung trong file nay */
static int u32KiemTraBienGlobalStatic = 10;

int main()
{
    Function_Static();
    Function_Static();

    return 0;
}

static void Function_Static(void)
{
    //static unsigned int u32KiemTraBienLocalStatic = 10;
    unsigned int u32KiemTraBienLocalStatic = 10;
    u32KiemTraBienLocalStatic++;
    printf("\n Gia tri u32KiemTraBienLocalStatic: %d", u32KiemTraBienLocalStatic);
}
