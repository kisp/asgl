Then(/^the output should be a set of strings$/) do
  x = parse_output(all_output)
  x.is_a?(Set) && x.all? {|e| e.is_a?(String) }
end

Then(/^the output should be eql to "(.*?)"$/) do |expected|
  parse_output(all_output).eql?(parse_output(expected))
end
