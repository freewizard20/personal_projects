import math

kconst = 10
minh = 200
maxh = 400
maxl = 50
alpha = 4
beta = 9

def removedots(str):
    sss = str.replace(".","")
    return sss

def reverse(s):
    if s=="":
        return s
    else:
        return reverse(s[1:])+s[0]
    
def lcs(a, b):
    lengths = [[0 for j in range(len(b)+1)] for i in range(len(a)+1)]
    # row 0 and column 0 are initialized to 0 already
    for i, x in enumerate(a):
        for j, y in enumerate(b):
            if x == y:
                lengths[i+1][j+1] = lengths[i][j] + 1
            else:
                lengths[i+1][j+1] = max(lengths[i+1][j], lengths[i][j+1])
    # read the substring out from the matrix
    result = ""
    x, y = len(a), len(b)
    while x != 0 and y != 0:
        if lengths[x][y] == lengths[x-1][y]:
            x -= 1
        elif lengths[x][y] == lengths[x][y-1]:
            y -= 1
        else:
            assert a[x-1] == b[y-1]
            result = a[x-1] + result
            x -= 1
            y -= 1
    return result

def isstoplr(i, str1, str2):
    try:
        if str1[i] == str2[i]:
            if str1[i+1] != str2[i+1]:
                if (str1[i-4:i+4].count('.')+str2[i-4:i+4].count('.')) >= 4:
                    return 1
                else:
                    return 0
            else:
                return 0
        else:
            return 0
    except:
        return 0

def isstopmm(i, str1, str2):
    try:
        if str1[i] == str2[i]:
            if str1[i+1] != str2[i+1]:
                if (str1[i-4:i+4].count('.')+str2[i-4:i+4].count('.')) >= 4:
                    return 1
                else:
                    return 0
            else:
                return 0
        else:
            return 0
    except:
        return 0

f = open("DNAseq.fasta","r")
mainseq = f.read()
mainseq = mainseq[22:]
maindic = {}
curr=0

for i in range(len(mainseq)):
    try:
        maindic[mainseq[i:i+10]].append(i)
    except:
        maindic[mainseq[i:i+10]] = [i]


while curr < len(mainseq):
    revkmer = 0
    minrange = curr + maxl
    maxrange = curr + maxh
    kmertmp = reverse(mainseq[curr:curr+kconst])
    try:
        #find rev kmer in maindic
        for j in range(len(maindic[kmertmp])):
            if (minrange < maindic[kmertmp][j]) & (maindic[kmertmp][j] < maxrange):
                revkmer = maindic[kmertmp][j]
    except:
        revkmer=0

    if revkmer == 0:
        curr=curr+1
        continue
    else:
        print(curr)
        #cut the candidate region
        candmin = curr - math.ceil((maxh-(revkmer-curr+30))/2)
        candmax = revkmer + 10 + math.floor((maxh-(revkmer-curr+30))/2)
        #find lcs for slr, smm'
        lcslr = lcs(mainseq[candmin:curr],mainseq[revkmer+10:candmax])
        lcsmm = lcs(mainseq[curr+10:revkmer],reverse(mainseq[curr+10:revkmer]))
        #make four indel included strings(indel dot)

        #make lr indel strings
        if lcslr == "":
            strl = "............."
            strr = "............."
        else:
            tmpl = mainseq[candmin:curr]
            tmpr = mainseq[revkmer+10:candmax]
            procl = ""
            procr = ""
            dumb = 0
            while (tmpl != "") | (tmpr !="") | (lcslr!=""):
                try:
                    if tmpl[0] == lcslr[0]:
                        if tmpr[0] == lcslr[0]:
                            procl = procl +tmpr[0]
                            procr = procr +tmpr[0]
                            tmpr = tmpr[1:]
                            tmpl = tmpl[1:]
                            lcslr = lcslr[1:]
                        else:
                            dumb = dumb+1
                    else:
                        procl=procl+tmpl[0]
                        procr=procr+"."
                        tmpl = tmpl[1:]
                        
        
                    if tmpr[0] == lcslr[0]:
                        if tmpl[0] == lcslr[0]:
                            procl = procl +tmpr[0]
                            procr = procr +tmpr[0]
                            tmpr = tmpr[1:]
                            tmpl = tmpl[1:]
                            lcslr = lcslr[1:]
                        else:
                            dumb = dumb+1
                        
                    else:
                        procr=procr+tmpr[0]
                        procl=procl+"."
                        tmpr = tmpr[1:]
                except:
                    
                    dumb = dumb+1
                    break

            strr = procr
            strl = procl

        #make mm indel strings
        if lcsmm == "":
            strm = "............."
            strmm = "............."
        else:
            tmpm = mainseq[curr+10:revkmer]
            tmpmm = reverse(mainseq[curr+10:revkmer])
            procm = ""
            procmm = ""
            dumb = 0
            while (tmpm != "") | (tmpmm !="") | (lcsmm!=""):
                try:
                    if tmpm[0] == lcsmm[0]:
                        if tmpmm[0] == lcsmm[0]:
                            procm = procm +tmpmm[0]
                            procmm = procmm +tmpmm[0]
                            tmpmm = tmpmm[1:]
                            tmpm = tmpm[1:]
                            lcsmm = lcsmm[1:]
                        else:
                            dumb = dumb+1
                    else:
                        procm=procm+tmpm[0]
                        procmm=procmm+"."
                        tmpm = tmpm[1:]
                        
        
                    if tmpmm[0] == lcsmm[0]:
                        if tmpl[0] == lcsmm[0]:
                            procm = procm +tmpmm[0]
                            procmm = procmm +tmpmm[0]
                            tmpmm = tmpmm[1:]
                            tmpm = tmpm[1:]
                            lcsmm = lcsmm[1:]
                        else:
                            dumb = dumb+1
                        
                    else:
                        procmm=procmm+tmpmm[0]
                        procm=procm+"."
                        tmpmm = tmpmm[1:]
                except:
                    
                    dumb = dumb+1
                    break
        
            strr = procr
            strl = procl
              
            strmm = procmm
            strm = procm
            
                
        # check for stop, until then record matches
        # check for lr stop    
        inormally = ""
        eatgumlikethis = ""
        i=0
        rstrl = reverse(strl)
        rstrr = reverse(strr)
        while not isstoplr(i,rstrl,rstrr):
            inormally = inormally + rstrl[i]
            eatgumlikethis = eatgumlikethis + rstrr[i]
            i = i+1

        inormally = reverse(inormally)
        eatgumlikethis = reverse(eatgumlikethis)
        
        # check for mmm stop
        inormally2 = ""
        eatgumlikethis2 = ""
        i=0
        rstrm = strm
        rstrmm = strmm
        while not isstopmm(i,rstrm,rstrmm):
            try:
                inormally2 = inormally2 + rstrm[i]
                eatgumlikethis2 = eatgumlikethis2 + rstrmm[i]
                i = i+1
            except:
                break
        
        # step 4 identify a hairpin sequence
        loopflag = 0
        # if for longer than half mmm stop length to split in half
        if len(inormally2) > math.floor((revkmer-(curr+10))/2):
            inormally2 = inormally[:math.celi((revkmer-(curr+10))/2)]
            eatgumlikethis2 = eatgumlikethis2[:math.ceil((revkmer - (curr+10))/2)]
            loop = ""
            loopflag = 1
        # parse the normally eating gummies

        
        tmp3 = reverse(inormally2)
        tmp4 = reverse(eatgumlikethis2)
        try:
            while tmp3[0]!=tmp4[0]:
                tmp3 = tmp3[1:]
                tmp4 = tmp4[1:]
        except:
            pass

        inormally2 = tmp3
        eatgumlikethis2 = tmp4

        try:
            while inormally[0] != eatgumlikethis[0]:
                inormally = inormally[1:]
                eatgumlikethis = eatgumlikethis[1:]
        except:
            pass
        # need to find loop
        
        if loopflag ==0:
            loop = mainseq[curr + 10 + len(inormally2) + 1 : revkmer - len(eatgumlikethis2) - 1]
            if len(loop)>50:
                loop = loop[:50]
        
        # make the candidates(answers?)
        candidateseq1 = inormally + mainseq[curr:curr+10] + inormally2
        candidateseq2 = eatgumlikethis + mainseq[revkmer:revkmer+10] + eatgumlikethis2

        
        
        # step 5 candidate satisfies the hairpin constaint        
        # trivial conditions?
        
        print(removedots(candidateseq1) + removedots(loop) + removedots(candidateseq2))
        print(removedots(candidateseq1))
        print(removedots(loop))
        print()
        print("-------------------------------------------------------")
        
        #step 6 : move to next range
        curr = candmax + 1



        # sorry for the unreadable dirty coding conventions.. will improve
        
        
        
        
        
