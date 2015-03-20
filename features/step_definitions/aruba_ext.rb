Given(/^a file named "(.*?)" with "(.*?)"$/) do |file_name, file_content|
  file_content = file_content.gsub(/\\n/, "\n")
  write_file(file_name, file_content)
end
