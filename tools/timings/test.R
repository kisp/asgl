#!/usr/bin/Rscript

args <- commandArgs(trailingOnly = TRUE)
inA = args[1]
inB = args[2]
print(c(inA, inB))

if (is.na(inA)) quit(status = 1)
if (is.na(inB)) quit(status = 1)

a = read.table(inA)
b = read.table(inB)

print(unique(a$exit.status))
print(unique(b$exit.status))

ta = a$time
tb = b$time

failed = (a$exit.status != 0) & (b$exit.status != 0)
ta = mapply(function(time,error) {if (error) NA else time }, a$time, failed)
tb = mapply(function(time,error) {if (error) NA else time }, b$time, failed)

print(cbind(problem = a[,"problem"],data.frame(ta = ta),data.frame(tb = tb)))

summary(ta)
summary(tb)

#t.test(ta, tb, paired=TRUE)
wilcox.test(ta, tb, paired=TRUE)
