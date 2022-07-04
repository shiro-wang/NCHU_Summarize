public class HW02_4108056004_1 extends ThreeSum{
    public HW02_4108056004_1(){
    }
    public int T_sum(int [] A){
        quick(A);
        int count = 0;
        int step = 0;
        int sum;
        while(A[step]<0){
            int head = step+1; 
            int tail = A.length-1;
            int a=A[step],b=A[head],c=A[tail];
            while(head < tail && A[tail] > 0){
                sum = b+c;
                if(sum > -a){
                    c = A[--tail];
                }else if(sum < -a){
                    b = A[++head];
                }else if (sum == -a){
                    count++;
                    head++;
                    tail--;
                    c = A[tail];
                    b = A[head];
                }
            }
            step++;
        }
        
        return count;
    }

    public static void quick(int[] number) {
        sort(number, 0, number.length-1);
    }
    
    private static void sort(int[] number, int left, int right) {
        if(left < right) { 
            int q = partition(number, left, right); 
            sort(number, left, q-1); 
            sort(number, q+1, right); 
        } 

    }

    private static int partition(int number[], int left, int right) {  
        int i = left - 1; 
        for(int j = left; j < right; j++) { 
            if(number[j] <= number[right]) { 
                i++; 
                swap(number, i, j); 
            } 
        } 
        swap(number, i+1, right); 
        return i+1; 
    } 

    private static void swap(int[] number, int i, int j) {
        int t = number[i]; 
        number[i] = number[j]; 
        number[j] = t;
    }
}
