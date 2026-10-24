Given(/^a file named "(.*?)" with "(.*?)"$/) do |file_name, file_content|
  # \\n, \\r and \\t in the text stand for newline, carriage return and tab
  file_content = file_content.gsub(/\\([nrt])/) { {"n" => "\n", "r" => "\r", "t" => "\t"}[$1] }
  write_file(file_name, file_content)
end
