#!/usr/bin/Rscript

rep = function(d) { sprintf("file contains %d rows", nrow(d)) }

## timeout in ms
timeout = 1000 * 50
## num of random samples
rsamp = 30

args <- commandArgs(trailingOnly = TRUE)
inputFile = args[1]
outputFile = args[2]
print(c(inputFile, outputFile))

if (is.na(inputFile)) quit(status = 1)
if (is.na(outputFile)) quit(status = 1)

sprintf("timeout is %fs", timeout / 1000)

sprintf("reading from file %s", inputFile)
d = read.table(inputFile)
rep(d)

d = d[!grepl("^rdm1000", d$file),]
sprintf("removing rdm1000 rows")
rep(d)

d = d[d$problem == "SE-PR",]
sprintf("keeping SE-PR rows")
rep(d)

d = d[d$exit.status == 0,]
sprintf("removing rows of exit.status not 0")
rep(d)

d = d[d$time >= 250 & d$time <= 7000,]
sprintf("keeping rows of time in [250ms <= time <= 7s]")
rep(d)

sprintf("taking a random sample of %d rows", rsamp)
d = d[sample(1:nrow(d), rsamp),]
rep(d)

d = d[d$time < (timeout*2),]
sprintf("removing rows of time < %f", (timeout*2)/1000.0)
rep(d)

wait = sum(pmin(timeout, d$time))
wait_warmup = nrow(d) * 400
wait_total = wait + wait_warmup
sprintf("expected run time is %3.1fs (%3.1fs + %3.1fs cache warmup)",
        wait_total/1000.0, wait/1000.0, wait_warmup/1000.0)

write.table(d[,c("problem", "file")], file = outputFile, quote = TRUE, row.names = FALSE, col.names = FALSE)
sprintf("problem set written to %s", outputFile)

write.table(
    sprintf(
        "./lisp-scripts/collect-timings.lisp -benchmarks-list %s -timeout %ss -results-file /tmp/r -overwrite-results t",
        outputFile, timeout/1000.0),
    quote = FALSE, row.names = FALSE, col.names = FALSE)
