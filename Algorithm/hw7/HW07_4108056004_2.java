public class HW07_4108056004_2 extends Buy_Phone{
    public HW07_4108056004_2(){
    }
    
    static int [][] anstemp = new int [1000][2];
    static int [][] aux = new int[1000][2];
    
    public int[][] bestPhone(int[][] array){
        int num = array.length;
        
        quick(array);
        
        int less = 0;
        int ansnum = 0;
        for(int i=num-1; i>-1; i--){
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

    public static void quick(int[][] number) {
        sort(number, 0, number.length-1);
    }
    
    private static void sort(int[][] number, int left, int right) {
        if(left < right) { 
            int q = partition(number, left, right); 
            sort(number, left, q-1); 
            sort(number, q+1, right); 
        } 

    }

    private static int partition(int number[][], int left, int right) {  
        int i = left - 1; 
        for(int j = left; j < right; j++) { 
            if(number[j][0] <= number[right][0]) { 
                if(number[j][0] == number[right][0]){
                    if(number[j][1] < number[right][1]){
                        number[j][1] = number[right][1];
                    }else{
                        number[right][1] = number[j][1];
                    }
                }
                i++; 
                swap(number, i, j); 
            }
        } 
        swap(number, i+1, right); 
        return i+1; 
    } 

    private static void swap(int[][] number, int i, int j) {
        int t = number[i][0]; 
        int x = number[i][1];
        number[i][0] = number[j][0]; 
        number[i][1] = number[j][1];
        number[j][0] = t;
        number[j][1] = x;
    }
}