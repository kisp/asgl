Given(/^a path from "(.*?)" to "(.*?)" named "(.*?)"$/) do |from, to, file|
  from = from.to_i
  to = to.to_i
  io = StringIO.new
  (from..to).each { |x| io.printf("arg(%d).\n", x) }
  (from..to-1).each { |x| io.printf("att(%d,%d).\n", x, x+1) }
  io.close
  write_file(file, io.string)
end
