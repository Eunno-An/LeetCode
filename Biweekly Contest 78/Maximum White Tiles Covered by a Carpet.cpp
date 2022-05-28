1차 22-05-28
Fail
회고
-> 오랜만에 보는 sliding window 문제. 진짜 딱 봐도 감 와야 되는데 오랜만에 봐서 그런지 감이 안왔다
-> 대충 비슷하게 풀긴 했는데, 어디서 나타난지 모르는 에러때문에 예외에서 걸렸다.
-> 핵심은 cover값의 의미를 알아야 한다. 그리고 좌표값 sorting, 그리고 sliding window를 적용할 수 있는 이유에 대해 다시 생각해 봐야 한다.
-> window, carpet, ruler, ... 비슷한 단어들이다
class Solution {
public:
    int maximumWhiteTiles(vector<vector<int>>& tiles, int carpetLen) {
        int res = 0, j =0, cover = 0;
        //cover=현재의 window에 의해 덮일 수 있는 하양색 타일의 길이.
        
        sort(begin(tiles), end(tiles));
        
        for(int i=0; res < carpetLen && i < tiles.size(); ){
            if(tiles[j][0] + carpetLen > tiles[i][1]){//j번째 시작점 + len이 i번째 타일의 오른쪽보다 더 길 때(더 덮을수 있는 여분이 생길 때)
                cover += tiles[i][1] - tiles[i][0] + 1;//i번째 타일 덮어
                res = max(res, cover);
                ++i;//그 다음 i번째꺼 볼게
            }
            else{//만약 j번째 시작점 + len이 i번째 타일의 오른쪽에 도달하지 못했어! 즉 i번쨰 타일을 부분 덮을수도 있고 안될수도 있어.
                int partial = max(0, tiles[j][0] + carpetLen - tiles[i][0]);//덮을 수 있는 여분이 i번째 타일에 도달하는지를 보는거지.
                res = max(res, cover + partial);
                cover -= (tiles[j][1] - tiles[j][0] + 1);//j번째 타일의 길이를 뺌으로써 그다음 window를 바로 조정할 수 있는거지! 그렇게 되면 우리는 tiles[j][1]부터 시작하는 window를 갖는거임!
                ++j;
            }
        }
        return res;
    }
};
