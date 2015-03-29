#!/usr/bin/Rscript

rep = function(d) { sprintf("file contains %d rows", nrow(d)) }

args <- commandArgs(trailingOnly = TRUE)
inputFile = args[1]
outputFile = args[2]
print(c(inputFile, outputFile))

if (is.na(inputFile)) quit(status = 1)
if (is.na(outputFile)) quit(status = 1)

cutoff = 1000 * 8
sprintf("timeout is %fs", cutoff / 1000)

sprintf("reading from file %s", inputFile)
d = read.table(inputFile)
rep(d)

d = d[d$exit.status == 0,]
sprintf("removing rows of exit.status not 0")
rep(d)

rsamp = 25
sprintf("taking a random sample of %d rows", rsamp)
d = d[sample(1:nrow(d), rsamp),]
rep(d)

d = d[d$time < (cutoff*2),]
sprintf("removing rows of time < %f", (cutoff*2)/1000.0)
rep(d)

sprintf("time to wait is %3.1fs", sum(pmin(cutoff, d$time))/1000.0)

write.table(d[,c("problem", "file")], file = outputFile, quote = FALSE, row.names = FALSE, col.names = FALSE)
sprintf("problem set written to %s", outputFile)
