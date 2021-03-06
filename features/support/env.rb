require 'aruba/cucumber'
require 'set'

Before do
    @aruba_timeout_seconds = 30
end

RSpec::Matchers.define :be_meql do |expected|
  match do |actual|
    actual == expected
  end
  failure_message do |actual|
    "but got #{actual.inspect}"
  end
end

RSpec::Matchers.define :be_meql_verbose do |expected|
  match do |actual|
    actual == expected
  end
  failure_message do |actual|
    "which evals to #{expected}\nbut got #{actual.inspect}"
  end
end

RSpec::Matchers.define :be_included_with_meql do |expected|
  match do |actual|
    expected.include? actual
  end
  failure_message do |actual|
    "but got #{actual.inspect}"
  end
end

class String
  def j2set
    case self
    when "YES"
      true
    when "NO"
      false
    else
      self
    end
  end
end

class Array
  def j2set
    a = self.map do |x|
      x.j2set
    end
    unless a.size == a.uniq.size
      raise "contains duplicates: #{a}"
    end
    a.to_set
  end
end

def convert_to_json(string)
  string.gsub(/([^\[, \n\]]+)/, '"\1"')
end

def parse_output(string)
  json = MultiJson.load(convert_to_json(string))
  json.j2set
end

def assert_newline_terminated(string)
  unless string[-1] == "\n"
    raise "not newline terminated:\n'#{string[-20..-1] || string}'"
  end
end

def is_array_of_strings?(x)
  x.is_a?(Array) &&
    x.all? { |elem| elem.is_a?(String) }
end

def is_set_of_strings?(x)
  is_array_of_strings?(x) &&
    x.uniq.length == x.length
end

def copy_to_tmp_auba(path)
  raise "tmp/aruba does not exit" unless File.exist?("tmp/aruba")
  begin
    FileUtils.copy(path, "tmp/aruba")
  rescue Exception
  end
end
