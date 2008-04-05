Dir.chdir(File.dirname(__FILE__) + '/../lib')

require 'shoes'
require 'sweetener'

describe Sweetener do
  it "should allow Shoes to parse and store a Sugar bundle ID" do
    ARGV.push('--sugar-bundle-id', '12345')
    Shoes::OPTS.parse!(ARGV)
    Shoes.sugar_bundle_id.should eql('12345')
  end

  it "should allow Shoes to parse and store a Sugar activity ID" do
    ARGV.push('--sugar-activity-id', '12345')
    Shoes::OPTS.parse!(ARGV)
    Shoes.sugar_activity_id.should eql('12345')
  end
end

