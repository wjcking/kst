 #include <tchar.h>
const char
    zeo = '0',
    one = '1', two = '2', thr = '3',
    fou = '4', fiv = '5', six = '6',
    sev = '7', eht = '8', nin = '9',

    csa = 'a', csb = 'b', csc = 'c', csd = 'd',
    cse = 'e', csf = 'f', csg = 'g', csh = 'h',
    csi = 'i', csj = 'j', csk = 'k', csl = 'l',
    csm = 'm', csn = 'n', cso = 'o', csp = 'p',
    csq = 'q', csr = 'r', css = 's', cst = 't',
    csu = 'u', csv = 'v', csw = 'w', csx = 'x',
    csy = 'y', csz = 'z',

    cba = 'A', cbb = 'B', cbc = 'C', cbd = 'D',
    cbe = 'E', cbf = 'F', cbg = 'G', cbh = 'H',
    cbi = 'I', cbj = 'J', cbk = 'K', cbl = 'L',
    cbm = 'M', cbn = 'N', cbo = 'O', cbp = 'P',
    cbq = 'Q', cbr = 'R', cbs = 'S', cbt = 'T',
    cbu = 'U', cbv = 'V', cbw = 'W', cbx = 'X',
    cby = 'Y', cbz = 'Z',
        //Connector cot  separator sot
    cnt = '-',
    cnr = '~',
    ace = ' ', con = ':',
    cma = ',', com = ',',
    duo = '.', dsh = '/',
    spt = '|',

    lsm = '(', lmd = '[', lbr = '{', lkt = '<',
    rsm = ')', rmd = ']', rbr = '}', rkt = '>', qos = '`',
        //�����������ź���ʵֽ�������ֻ��+
    cpp = '+',

    alm = '!', per = '%',
    cxp = '#', and = '&',
    dor = '$',

    sdr = '*',
    eqt = '=',
    qst = '?',
    atr = '@',
    dsa = '\\',
    art = '^',
    udr = '_';
 const char 
    //ת������
    eslt = '\n',  //����(LF) ��010 
    esnt = '\r',  //�س�(CR) ������ǰλ���Ƶ����п�ͷ 013
    estb = '\t',       //ˮƽ�Ʊ�(HT)  009
    esds = '\\',  //����һ����б���ַ�''\'   092
    essq = '\'',  //����һ�������ţ�Ʋ�ţ��ַ� 039
    esqo = '\"',  //����һ��˫�����ַ� 034 
    esno = '\0'; //���ַ�(NUL) 000