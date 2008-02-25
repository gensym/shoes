require 'dbus'

class Shoes
  class SugarDBusService < DBus::Object
    include Singleton

    dbus_interface 'org.laptop.Activity' do
      dbus_method(:SetActive, 'in active:b') { }
      dbus_method(:Invite, 'in buddy_key:s') { }
      dbus_method(:TakeScreenshot, '') { }
    end

    def initialize
      @service = make_service
      super(object_path)
    end

    private

    def make_service
      ::DBus::SystemBus.instance.request_service("org.laptop.Activity#{Shoes.sugar_activity_id}")
    end

    def object_path
      "/org/laptop/Activity/#{Shoes.sugar_activity_id}"
    end
  end
end
