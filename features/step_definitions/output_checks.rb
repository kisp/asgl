Then(/^the output should be a set of strings$/) do
  x = parse_output(all_output)
  x.is_a?(Set) && x.all? {|e| e.is_a?(String) }
end

Then(/^the output should be eql to "(.*?)"$/) do |expected|
  a = parse_output(all_output)
  b = parse_output(expected)
  expect(a).to be_meql(b)
end

Then(/^the output should be eql to:$/) do |expected|
  a = parse_output(all_output)
  b = parse_output(expected)
  expect(a).to be_meql(b)
end

Then(/^the output should be eql to one of:$/) do |set_of_poss|
  o = parse_output(all_output)
  s = parse_output(set_of_poss)
  expect(o).to be_included_with_meql(s)
end
