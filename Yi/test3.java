class test3{
    public static int[][] mult(int [][] matrix){
        
    }
    public static void main(String[] args) {
        int [][] matrix = {{5,3,6},{2,3,4},{1,3,2}};
        int [][] ans = mult(matrix);

        for(int i = 0; i < matrix.length; i++){
            for(int j = 0; j < matrix[i].length; j++)
                System.out.print(matrix[i][j] + " ");
            System.out.println();
        }

        System.out.println("-----------------------------");

        for(int i = 0; i < matrix.length; i++){
            for(int j = 0; j < matrix[i].length; j++)
                System.out.print(ans[i][j] + " ");
            System.out.println();
        }
    }   
}