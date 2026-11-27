import java.util.*;

public class Main{
  public static void main(String[] args){
    Scanner sc = new Scanner(System.in);
    int n = sc.nextInt();
    int x = sc.nextInt();

    int [] arr = new int[n];

    for(int i = 0; i < n; ++i){
      arr[i] = sc.nextInt();
    }

    int fast = 0, slow = 0;
    for(;fast < arr.length; ++fast){
      if(arr[fast] != x)
        arr[slow++] = arr[fast];
    }

    for(int i = 0; i < slow; ++i){
      if(i > 0) System.out.print(" ");
      System.out.print(arr[i]);
    }

    sc.close();
  }
}
