Given(/^a file named "(.*?)" with "(.*?)"$/) do |file_name, file_content|
  # \\n, \\r and \\t in the text stand for newline, carriage return and tab
  file_content = file_content.gsub(/\\([nrt])/) { {"n" => "\n", "r" => "\r", "t" => "\t"}[$1] }
  write_file(file_name, file_content)
end

# \n, \r, \t, \" and \\ in the text stand for newline, carriage return, tab,
# quote and backslash; an empty text is an empty standard input
def unescape_text(text)
  text.gsub(/\\([nrt"\\])/) { { "n" => "\n", "r" => "\r", "t" => "\t", '"' => '"', "\\" => "\\" }[$1] }
end

When(/^I run `([^`]*)` with the input "(.*)"$/) do |cmd, input|
  run_interactive(unescape(cmd))
  text = unescape_text(input)
  _write_interactive(text) unless text.empty?
  close_input
end

# SE- problems: any one of the extensions is a right answer
Then(/^the output should be one extension of "(.*?)"$/) do |extensions|
  assert_newline_terminated(all_stdout)
  expect(parse_output(all_stdout)).to be_included_with_meql(parse_output(extensions))
end
