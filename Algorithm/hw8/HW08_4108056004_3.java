public class HW08_4108056004_3 extends Buy_Phone_v2{
    public HW08_4108056004_3(){
    }
    
    static int [][] anstemp = new int [1000][6];
    static int [][] aux = new int[1000][6];
    static boolean tf;
    
    public int[][] bestPhone(int[][] array){
        boolean all_tf = true;
        int num = array.length;
        int ansnum = 1;
        merge(array);
        anstemp[0] = array[0];
        
        for(int i=1;i<num;i++){
            for(int k=0;k<ansnum;k++){
                tf = false;
                for(int j=1;j<6;j++){
                    if(array[i][j]>anstemp[k][j]){
                        tf = true;
                    }
                }
                if(tf){
                   all_tf = true; 
                }else{
                    all_tf = false;
                    break;
                }
            }
            if(all_tf){
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
            else if(aux[j][0] == aux[i][0]){
                int l = 1;
                while(aux[j][l] == aux[i][l] && l<5) l++;
                if(aux[j][l]>aux[i][l]) number[k] = aux[j++];
                else number[k] = aux[i++];
            }
            else if(aux[j][0]>aux[i][0]) number[k] = aux[j++];
            else number[k] = aux[i++];
            
        }
        for(i=lo;i<=hi;i++){
            aux[i]=number[i];
        }
    } 
}