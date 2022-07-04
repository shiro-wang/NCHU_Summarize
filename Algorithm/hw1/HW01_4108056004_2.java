import java.util.Scanner;
public class HW01_4108056004_1 extends ArrayData{
    public HW01_4108056004_1(int [] A){
        this.A=A;
    }
    public static void main(String args[]){

        String str = input.nextLine();
        String[] num = str.split(" ");
        int[] nums = new int[num.length];
        for(int i=0;i<num.length;i++) {
            nums[i] = Integer.parseInt(num[i]);
        }
        
        HW01_4108056004_1 test = new HW01_4108056004_1(nums);
        System.out.println("Max = "+test.max());
        System.out.println("Min = "+test.min());
        input.close();
    }

    @Override
    public int max(){
        int max=A[0];
        for(int i=0;i<A.length;i++){
            if(A[i]>max){
                max=A[i];
            }
        }
        return max;
    }

    @Override
    public int min(){
        int min=A[0];
        for(int i=0;i<A.length;i++){
            if(A[i]<min){
                min=A[i];
            }
        }
        return min;
    }
}