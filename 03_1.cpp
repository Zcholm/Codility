int solution(int X, int Y, int D) {
    int edge = 0;
    if ((Y-X) % D ) {
        edge = 1;
    }
    return (Y-X) / D + edge; 
}