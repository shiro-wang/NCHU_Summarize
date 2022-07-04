public class HW07_4108056004_1 extends Buy_Phone{
    public HW07_4108056004_1(){
    }
    
    static int [][] anstemp = new int [1000][2];
    static int [][] aux = new int[1000][2];
    
    public int[][] bestPhone(int[][] array){
        int num = array.length;
        
        merge(array);
        
        int less = 0;
        int ansnum = 0;
        for(int i=0; i<num; i++){
            if(array[i][1]>less){
                less = array[i][1];
                anstemp[ansnum++] = array[i];
            }
        }
        
        int [][] result = new int[ansnum][2];
        for(int i=0;i<ansnum;i++){
            result[ansnum-i-1] = anstemp[i];
        }

        return result;
    }

    public static void merge(int[][] number){
        for(int i=0;i<number.length;i++){
            aux[i] = number[i];
        }
        sort(number, aux, 0, number.length-1);
    }
    
    private static void sort(int[][] number, int[][] aux, int lo, int hi) {
        if(hi<=lo) return;
        
        int mid = lo + (hi - lo)/2;
        sort(number,aux,lo,mid);
        sort(number,aux,mid+1,hi);
        mergesort(number,aux,lo,mid,hi);
    }

    private static void mergesort(int number[][],int[][] aux, int lo,int mid, int hi) {  
        int i = lo;
        int j = mid+1;
        for(int k=lo; k<=hi; k++){
            if(i>mid) number[k] = aux[j++];
            else if(j>hi) number[k] = aux[i++];
            else if(aux[j][0]>aux[i][0]) number[k] = aux[j++];
            else if(aux[i][0]>aux[j][0]) number[k] = aux[i++];
            else{
                if(aux[j][1]>aux[i][1]) number[k] = aux[j++];
                else number[k] = aux[i++];
            } 
        }
        for(i=lo;i<=hi;i++){
            aux[i]=number[i];
        }
    } 
}