public class HW03_4108056004_1 extends HillFinding{
    public HW03_4108056004_1(){
    }
    
    public int H_Finding(int [] A){
        int total = A.length;
        int result = findn(A,0,total);
        return total-1-result-1;
    }

    public int findn(int [] A, int head, int tail){
        boolean tf = true;
        int mid, i;
        int total = tail;
        while(tf){
            if(head != tail){
                mid = (tail - head)/2 + head;
                if(A[mid]>A[head]){
                    head = mid;
                }else if(A[mid]<A[head]){
                    tail = mid;
                }else if(A[mid] == A[head]){
                    if(head != tail){
                        for(i=head; i<tail;i++){
                            if(A[i]>A[i+1]){
                                tf = false;
                                return i;
                            }
                        }
                        return total;
                    }          
                }
            }else{
                tf = false;
                return A[head];
            }
        }
        return 0;
    }
}