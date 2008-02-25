Dir.chdir(File.dirname(__FILE__) + '/../lib')

require 'shoes'
require 'shoes-dbus'
require 'dbus'

Spec::Runner.configure do |config|
  config.mock_with :flexmock
end

describe "A SugarDBusService D-Bus exported object" do
  before :each do
    bus = flexmock('bus')
    @example_activity_id = '12345'
    
    flexmock(Shoes).should_receive(:sugar_activity_id).and_return(@example_activity_id)
    flexmock(DBus::SystemBus).should_receive(:instance).and_return(bus)
    bus.should_receive(:request_service).with("org.laptop.Activity#{@example_activity_id}")

    @dbus_object = Shoes::SugarDBusService.instance
  end

  it 'should be a DBus object implementing org.laptop.Activity' do
    @dbus_object.intfs.keys.should include('org.laptop.Activity')
  end

  it 'should have an object path of the form /org/laptop/Activity/activity_id' do
    @dbus_object.path.should == "/org/laptop/Activity/#{@example_activity_id}"
  end

  it 'should provide org.laptop.Activity.SetActive(b: active)' do
    methods = @dbus_object.intfs['org.laptop.Activity'].methods
    methods.should include(:SetActive)
    methods[:SetActive].params.length.should == 1
    methods[:SetActive].params.should include(['active', 'b'])
  end

  it 'should provide org.laptop.Activity.TakeScreenshot' do
    methods = @dbus_object.intfs['org.laptop.Activity'].methods
    methods.should include(:TakeScreenshot)
    methods[:TakeScreenshot].params.length.should == 0
  end

  it 'should provide org.laptop.Activity.Invite(s: buddy_key)' do
    methods = @dbus_object.intfs['org.laptop.Activity'].methods
    methods.should include(:Invite)
    methods[:Invite].params.length.should == 1
    methods[:Invite].params.should include(['buddy_key', 's'])
  end
end

describe Shoes::SugarDBusService do
  it 'should be a singleton' do
    Shoes::SugarDBusService.ancestors.should include(Singleton)
  end

  it 'should be a DBus::Object subclass' do
    Shoes::SugarDBusService.ancestors.should include(DBus::Object)
  end
end
