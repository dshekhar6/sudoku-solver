class sudoku
{
    private:
        int arr[9][9];
        int level;

        bool cntRow(int i, int x)
        {
            int c = 0;
            for(int j=0; j<9; j++)
                if(arr[i][j] == x)
                    return 1;
            return 0;
        }

        bool cntCol(int j, int x)
        {
            int c = 0;
            for(int i=0; i<9; i++)
                if(arr[i][j] == x)
                    return 1;
            return 0;
        }

        void detCen(int& i, int& j)
        {
            if(i%3==0)
                i++;
            if(i%3==2)
                i--;
            if(j%3==0)
                j++;
            if(j%3==2)
                j--;
        }

        bool cntSlot(int i, int j, int x)
        {
           detCen(i, j);
           int c = 0;
           c += (arr[i][j] == x);
           c += (arr[i][j+1] == x);
           c += (arr[i][j-1] == x);
           c += (arr[i+1][j] == x);
           c += (arr[i-1][j] == x);
           c += (arr[i+1][j+1] == x);
           c += (arr[i+1][j-1] == x);
           c += (arr[i-1][j+1] == x);
           c += (arr[i-1][j-1] == x);
           return (c);
        }

        bool canPlace(int i, int j, int x)
        {
            return (!cntRow(i, x) and !cntCol(j, x) and !cntSlot(i, j, x));
        }


        bool solveMain(int i, int j)
        {

            if(i==9)
                return 1;
            if(j==9)
                return solveMain(i+1, 0);
           
            if(this->get(i, j))
                return solveMain(i, j+1);

            for(int k=1; k<=9; k++)
            {
                if(this->set(i, j, k))
                {
                    bool ret = solveMain(i, j+1);
                    if(ret)
                        return 1;
                }
                this->clear(i, j);
            }
          
            return 0;
        }


        void gen()
        {
            level++;
            solveMain(0, 0);
            for(int i=0; i<9; i++)
                for(int j=0; j<9; j++)
                {
                    if((bool)(rand()%level))
                    {
                        arr[i][j] = 0;
                    }
                        
                }

        }


    public:
        sudoku(int level)
        {
            this->level = min(level, 10);
            for(int i=0; i<9; i++)
                for(int j=0; j<9; j++)
                    arr[i][j] = 0;

            gen();
        }


        void reCreate(int level)
        {
            this->level = min(level, 10);
            gen();
        }
        

        bool set(int i, int j, int x)
        {
            if(canPlace(i, j, x))
            {
                arr[i][j] = x;
                return 1;
            }

            return 0;
        }

        int get(int i, int j)
        {
            return arr[i][j];
        }

        void clear(int i, int j)
        {
            arr[i][j] = 0;
        }

        void print()
        {
            for(int i=0; i<9; i++)
            {
                for(int j=0; j<9; j++)
                    cout << arr[i][j] << " ";
                cout << endl;
            }

        }
};
