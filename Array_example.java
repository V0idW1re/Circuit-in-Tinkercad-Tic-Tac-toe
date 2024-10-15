

/****************  Array:Fill, Sum, Max-Min, Find.  ****************/


import java.util.Arrays;
import java.util.Random;
import java.util.Scanner;

public class Array_example {
    static int[] myArray = new int[10];     // Δημιουργώ Array 10 θέσεων
    static Scanner keyb= new Scanner(System.in);


    public static void main(String[] args){
        int choice;
        do{     // Επιλογές εμφάνισης
            System.out.println();
            System.out.println("---> Type 1-5 <---");
            System.out.println("1. Fill Array");
            System.out.println("2. Sum of Array Elements");
            System.out.println("3. Find Min-Max");
            System.out.println("4. Look for a Number");
            System.out.println("5. Exit");
            System.out.println();
            choice=keyb.nextInt();
            switch(choice){    //  Μέθοδοι επιλογής
                case 1:
                    fill_array();
                    break;
                case 2:
                    sum_of_array_elements();
                    break;
                case 3:
                    find_min_max();
                    break;
                case 4:
                    look_for_a_number();
                    break;
                case 5:
                    break;
                default:
                    System.out.println("(Wrong number)");   //Για αριθμό εκτός ορίου
                    break;
            }
        }while (choice!=5);     // Περιορισμός!
    }
    static void fill_array(){       //Μέθοδος Γεμίσματος
        System.out.println();
        System.out.println("The number are: ");
        Random r1 = new Random();
        for(int i=0; i<myArray.length; i++){
            myArray[i]=r1.nextInt(100)+1;
            System.out.print(myArray[i]+" ");
        }
        System.out.println();
        System.out.println("The numbers in order are: "); /*** Για Arrays.binarySearch ***/
        Arrays.sort(myArray);
        for (int i=0; i<myArray.length; i++){
            System.out.print(myArray[i]+" ");
        }
        System.out.println();
    }
    static void sum_of_array_elements(){       //Μέθοδος Αθροίσματος
        int sum=0;
        System.out.println();
        for (int i=0; i<myArray.length; i++){
            sum+=myArray[i];
        }
        if (sum == 0)
            System.out.println("(Empty Array)");
        else
            System.out.println("Sum is: "+sum);
    }
    static void find_min_max(){       //Μέθοδος Μεγαλύτερου και Μικρότερου
        int min, max, minpos, maxpos;
        max=min=myArray[0];
        minpos=maxpos=0;
        System.out.println();
        for (int i=0; i<10; i++){
            if (myArray[i]<min) {
                min = myArray[i];
                minpos = i;
            }
            if (myArray[i]>max) {
                max = myArray[i];
                maxpos = i;
            }
        }
        minpos +=1;
        maxpos +=1;
        System.out.println("Minimum is: "+min+", in posision: "+minpos);
        System.out.println("Maximum is: "+max+", in posision: "+maxpos);
    }
    static void look_for_a_number(){       //Μέθοδος Αναζήτησης
        System.out.println();
        /* int number;
        boolean found=false;
        System.out.print("Type Number: ");
        number=keyb.nextInt();
        System.out.println();
        for (int i=0; i<myArray.length; i++){
            if (myArray[i]==number){
                found=true;
                i+=1;
                System.out.println("Number is in position: "+i);
            }
        }
        if (found==false)
        {
            System.out.println("(No number found)");
        }
*/
        /*** Αντι για boolean με Arrays.binarySearch ***/

        int number;
        int pos;
        System.out.print("Give a number: ");
        number = keyb.nextInt();
        System.out.println();
        pos=Arrays.binarySearch(myArray, number);//works only for sorted arrays
        if(pos >=0) {
            pos += 1;
            System.out.println("Found at position " + pos);
        }
        else
            System.out.println("Number was not found");

    }
}

