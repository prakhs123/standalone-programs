/** ||||||||||||||||||||||||||||||||||||||||||||||| **/
/** *********** BEGIN FAST I/O ******************** **/
/** ||||||||||||||||||||||||||||||||||||||||||||||| **/
#define BUFSIZE 6000000
char inbuf[BUFSIZE],outbuf[BUFSIZE],c,*in,*out;
int nbuf[10],nbs,bi;
int neg,num;
 
void io_init(){
    fread(inbuf,1,BUFSIZE,stdin);
    in = inbuf;
    out = outbuf;
}
 
int ni(){
    c = *in++;neg = num = 0;
    while(!(c >= '0' && c <= '9' || c == '-') ) c = *in++;
    if(c == '-') neg = 1, c = *in++;
    while(c >= '0' && c <= '9'){
        num = (num << 3) + (num << 1) + c - '0';
        c = *in++;
    }
    --in;
    return neg ? -num : num;
}
 
char nc(){
    c = *in++;
    while(!(c == 'I' || c == 'D' || c == 'K' || c == 'C')) c = *in++;
    --in;
    return c;
}
 
void oi(int num){
    if(num < 0) *out++ = '-' , num = -num;
    nbs = bi = 0;
    if(num == 0) nbuf[nbs++] = 0;
    while(num) nbuf[nbs++] = num%10 , num /= 10;
    bi = nbs - 1;
    while(bi >= 0) *out++ = nbuf[bi--] + '0';
    *out++ = '\n';
}
 
void os(char *s){
    while(*s) *out++ = *s++;
    *out++ = '\n';
}
 
void io_end(){
    *out = '\0';
    assert(out  - outbuf <= BUFSIZE && out - outbuf >= 0);
    fwrite(outbuf,1,out - outbuf,stdout);
}
/** ||||||||||||||||||||||||||||||||||||||||||||||| **/
/** *********** END FAST I/O ********************** **/
/** ||||||||||||||||||||||||||||||||||||||||||||||| **/