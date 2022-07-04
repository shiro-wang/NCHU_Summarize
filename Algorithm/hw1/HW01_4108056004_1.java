public class HW01_4108056004_1 extends ArrayData{
    public HW01_4108056004_1(int [] A){
        this.A=A;
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