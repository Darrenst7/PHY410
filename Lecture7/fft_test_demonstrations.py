import matplotlib.pyplot as plt

from fft import fft
from fft import ifft
from fft import fft_power
from numpy import array
from numpy import real
import math
import time
import numpy

plotfirst = True

if plotfirst == False : 
    # make some fake data as a single-frequency sinusoid

    N = 1024      # number of samples
    f = 10.0      # frequency / N
    m = 0.00      # linear slope, if desired

    # For demonstrations : 
    clip = 200      # "clip" so we can pad with zeros
    window = True # window or not? 
    
    
    x = array([ float(i) for i in xrange(N) ] )
    if window : 
        y = array([ math.sin(-2*math.pi*f* xi / float(N)) *(0.5 - 0.5 * math.cos(2*math.pi*xi/float(N-1)))  + m*xi  for xi in x ])
    else :
        y = array([ math.sin(-2*math.pi*f* xi / float(N)) + m*xi  for xi in x ])

    for i in range(N-clip, N) :
        y[i] = 0.0

    start_time = time.time()
    Y = fft(y)
    print time.time() - start_time, " seconds" 

    powery = fft_power(Y)
    powerx = array([ float(i) for i in xrange(len(powery)) ] )


    Yre = [math.sqrt(Y[i].real**2 + Y[i].imag**2) for i in xrange(N)]

    s1 = plt.subplot(2, 1, 1)
    plt.plot( x, y )

    s2 = plt.subplot(2, 1, 2)
    s2.set_autoscalex_on(False)
    p1, = plt.plot( powerx, powery )
    p2, = plt.plot( x, Yre )
    s2.legend( [p1, p2], ["Power", "Magnitude"] )
    plt.xlim([0,N/4])
    plt.yscale('log')
    plt.show()


else : 
    # data downloaded from ftp://ftp.cmdl.noaa.gov/ccg/co2/trends/co2_mm_mlo.txt
    print ' C02 Data from Mauna Loa'
    data_file_name = 'co2_mm_mlo.txt'
    file = open(data_file_name, 'r')
    lines = file.readlines()
    file.close()
    print ' read', len(lines), 'lines from', data_file_name

    window = True

    yinput = []  #data === interpolated/avg/trend
    xinput = []  #dates

    for line in lines :
        if line[0] != '#' :
            try:
                year = int(line[0:4])
                if year > 1957 and year < 2018:
                    words = line.split()
                    xval = float(words[2])  # dates
                    yval = float( words[4] )# data 3=avg, 4=inter, 5=trend
                    yinput.append( yval )
                    xinput.append( xval )
            except ValueError :
                print 'bad data:',line
                
#    yinput2 = yinput
    yinput3 = []
    xinput3 = []



    for i in range(0,len(yinput)):
        if yinput[i] > 0:
            xinput3.append(xinput[i])
            yinput3.append(yinput[i])



N = len(yinput) # length of data
log2N = math.log(N, 2)
if log2N - int(log2N) > 0.0 :
    print 'Padding with zeros!'
    pads = [300.0] * (pow(2, int(log2N)+1) - N)
    yinput = yinput + pads
    N = len(yinput)
    print 'Padded : '
    print len(yinput)
        # Apply a window to reduce ringing from the 2^n cutoff
    if window : 
        for iy in xrange(len(yinput)) :
            yinput[iy] = yinput[iy] * (0.5 - 0.5 * math.cos(2*math.pi*iy/float(N-1)))




    y = array( yinput ) 
    x = array([ float(i) for i in xrange(len(y)) ])
    Y = fft(y)
#    y2 = array( yinput2 ) 
#    x2 = array( xinput )

    maxfreq = 200  
    # Now smooth the data
    for iY in range(maxfreq, len(Y)-maxfreq ) :
        Y[iY] = complex(0,0)

        Y[iY] = Y[iY] * (0.5 - 0.5 * math.cos(2*math.pi*iY/float(N-1)))

        ysmoothed = ifft(Y)
        ysmoothedreal = real(ysmoothed)


  #  y3 = array( yinput3 )
   # x3 = array( xinput3 )

    powery = fft_power(Y)
    powerx = array([ float(i) for i in xrange(len(powery)) ] )

    Yre = [math.sqrt(Y[i].real**2+Y[i].imag**2) for i in xrange(len(Y))]

#coefficents= numpy.polyfit(x3,y3,2)
#polynomial= numpy.poly1d(coefficents)
#print polynomial

    ay = plt.subplot(2, 1, 1)
    g1, = plt.plot(x, y)
    g2, = plt.plot( x, ysmoothedreal)
    ay.legend( [g1,g2], ['Initial Graph', 'Smoothed Graph'] )

 #   plt.plot( x, y )

    ax = plt.subplot(2, 1, 2)
    p1, = plt.plot( powerx, powery )
    p2, = plt.plot( x, Yre )
    ax.legend( [p1, p2], ["Power", "Magnitude"] )
    plt.yscale('log')


    plt.show()


