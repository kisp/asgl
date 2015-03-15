require 'aruba/cucumber'
require 'set'

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
  string.gsub(/([[:alnum:]]+)/, '"\1"')
end

def parse_output(string)
  json = MultiJson.load(convert_to_json(string))
  json.j2set
end

def is_array_of_strings?(x)
  x.is_a?(Array) &&
  x.all? { |elem| elem.is_a?(String) }
end

def is_set_of_strings?(x)
  is_array_of_strings?(x) &&
  x.uniq.length == x.length
end
