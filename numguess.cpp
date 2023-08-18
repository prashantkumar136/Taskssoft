import java.util.*;
class Numguess{
    public static void main(String[] args)
    {
       do{
            Random rand = new Random();
            int randomNumber = rand.nextInt(100)+1;

            Scanner sc = new Scanner(System.in);
            int attempts= 10;
            int count = 0;
            while(attempts-- > 0 )
            {
                System.out.println("enter you guess (1-100) : ");
                int guess = sc.nextInt();
            
                if(guess == randomNumber)
                {
                    System.out.println("Congratulations! You found it!");
                    randomNumber = rand.nextInt(100)+1;
                    count++;
                }
                else if(guess > randomNumber)
                    System.out.println("your guess is greater than random number");
                else 
                    System.out.println("your guess is lower than random number");
            }
            System.out.println("your score is : "+count+"/10");
            System.out.println("your point is : "+count*10+"/100");
            System.out.println("Do you want to play again enter (Y) else enter (N) : ");
            String c = sc.next();
            if(c.charAt(0) == 'N')
                break;
        }while(true);
    }
}