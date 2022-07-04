public class HW02_4108056004_2 extends ThreeSum{
    public HW02_4108056004_2(){
    }
    public int T_sum(int [] A){
        quick(A);
        int count = 0;
        int negative_min=0;
        for(int i=0;i<A.length;i++){
            if(A[i]>-1){
                negative_min = i-1;
                break;
            }
        }
        int split_negative = negative_min/8;
        if(negative_min == 0){
            tsum wtf = new tsum(A, 0, A.length-1);
            wtf.run();
            return wtf.count;
        }else{
            int temp;

            tsum first = new tsum(A, 0, split_negative);
            tsum second = new tsum(A, split_negative+1, split_negative+split_negative);
            temp = split_negative+split_negative;
            tsum third = new tsum(A, temp+1, temp+split_negative);
            temp += split_negative;
            tsum fourth = new tsum(A, temp+1, temp+split_negative);
            temp += split_negative;
            tsum fifth = new tsum(A, temp+1, temp+split_negative);
            temp += split_negative;
            tsum sixth = new tsum(A, temp+1, temp+split_negative);
            temp += split_negative;
            tsum seventh = new tsum(A, temp+1, temp+split_negative);
            temp += split_negative;
            tsum eighth = new tsum(A, temp+1, negative_min);
            first.start();
            second.start();
            third.start();
            fourth.start();
            fifth.start();
            sixth.start();
            seventh.start();
            eighth.start();
            try{
                first.join();
                second.join();
                third.join();
                fourth.join();
                fifth.join();
                sixth.join();
                seventh.join();
                eighth.join();
            }catch(InterruptedException e){
            }
            count = first.count+second.count+third.count+fourth.count+fifth.count+sixth.count+seventh.count+eighth.count;
            
            return count;
        }
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
    public class tsum extends Thread{
        int [] A;
        int step, step_end;
        public tsum(int [] A,int step, int step_end){
            this.A = A;
            this.step = step;
            this.step_end = step_end;
        }
        int count = 0;
        public void run(){
            int sum;
            while(step < step_end+1){
                int head = step+1; 
                int tail = A.length-1;
                int a=A[step],b=A[head],c=A[tail];
                while(head < tail && A[tail] > 0){
                    sum = b+c;
                    if(sum > -a){
                        tail--;
                        c = A[tail];
                    }else if(sum < -a){
                        head++;
                        b = A[head];
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
        }
    }
}

