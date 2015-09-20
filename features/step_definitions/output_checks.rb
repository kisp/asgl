Then(/^the output should be a set of strings$/) do
  assert_newline_terminated(all_stdout)
  x = parse_output(all_stdout)
  x.is_a?(Set) && x.all? {|e| e.is_a?(String) }
end

Then(/^the output should be eql to "(.*?)"$/) do |expected|
  assert_newline_terminated(all_stdout)
  a = parse_output(all_stdout)
  b = parse_output(expected)
  expect(a).to be_meql(b)
end

Then(/^the output should be eql to:$/) do |expected|
  assert_newline_terminated(all_stdout)
  a = parse_output(all_stdout)
  b = parse_output(expected)
  expect(a).to be_meql(b)
end

Then(/^the output should be eql to one of:$/) do |set_of_poss|
  assert_newline_terminated(all_stdout)
  o = parse_output(all_stdout)
  s = parse_output(set_of_poss)
  expect(o).to be_included_with_meql(s)
end

Then(/^the output should be eql to ruby "(.*?)"$/) do |expr|
  b = eval(expr)
  assert_newline_terminated(all_stdout)
  a = parse_output(all_stdout)
  expect(a).to be_meql_verbose(b)
end

Then(/^the output should be eql to ruby:$/) do |expr|
  b = eval(expr)
  assert_newline_terminated(all_stdout)
  a = parse_output(all_stdout)
  expect(a).to be_meql_verbose(b)
end
