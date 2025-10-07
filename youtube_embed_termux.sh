#!/data/data/com.termux/files/usr/bin/bash

if [ -z "$3" ]
then
echo "youtube_embed.sh 00:00:00 00:01:02 https://youtu.be/2PNY4RxISKw"
echo "youtube_embed.sh 01:11:35 01:22:59 https://youtu.be/2PNY4RxISKw"
exit 1
fi

#echo $1
cas1=$1
#echo $cas1
h1=${cas1:0:2}
#echo $h1
m1=${cas1:3:2}
#echo $m1
s1=${cas1:6:2}
#echo $s1
v1=$(( $h1 * 3600 + $m1 * 60 + s1))
#echo $v1

#echo #2
cas2=$2
#echo $cas2
h2=${cas2:0:2}
#echo $h2
m2=${cas2:3:2}
#echo $m1
s2=${cas2:6:2}
#echo $s2
v2=$(( $h2 * 3600 + $m2 * 60 + s2))
#echo $v2

url=$3
#echo $3

str1="https://www.youtube.com/embed/"

d_url=${#url}
#echo $d_url

d2_url=$(( $d_url - 11 ))
#echo $d2_url

#str2=${url:5:11}
str2=${url:$d2_url:11}
#echo $str2


# tisk vysledku
if [ $v1 == 0 ]
then
# start bude od uplneho zacatku videa plati ze $1 = 00:00:00
# https://www.youtube.com/embed/IQrdyTrOUsQ?autoplay=1&mute=1&end=81&vq=large
out1=$str1
out1+=$str2
out1+="?autoplay=1&mute=1&end="
out1+=$v2
# out1+="&vq=large"
# parametr vq=large muze bej a nemusi, dle libosti (video quality)
out1+="&vq=large"
echo $out1

out2=$str1
out2+=$str2
out2+="?end="
out2+=$v2
# out2+="&vq=large"
# parametr vq=large muze bej a nemusi, dle libosti (video quality)
out2+="&vq=large"
echo $out2

else
# start nebude od uplneho zacatku videa ale bude se brat v potaz nenulova hodnota poctu vterin od zacatku $v1"
# https://www.youtube.com/embed/IQrdyTrOUsQ?autoplay=1&mute=1&start=60&end=70
out3=$str1
out3+=$str2
out3+="?autoplay=1&mute=1&start="
out3+=$v1
out3+="&end="
out3+=$v2
# out3+="&vq=large"
out3+="&vq=large"
echo $out3

out4=$str1
out4+=$str2
out4+="?start="
out4+=$v1
out4+="&end="
out4+=$v2
# out4+="&vq=large"
out4+="&vq=large"
echo $out4

fi
