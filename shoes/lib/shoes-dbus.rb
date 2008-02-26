require 'dbus'

class Shoes
  class SugarDBusService < DBus::Object
    include Singleton

    attr_accessor :on_set_active
    attr_accessor :on_invite
    attr_accessor :on_take_screenshot

    dbus_interface 'org.laptop.Activity' do
      dbus_method(:SetActive, 'in active:b') { |active| on_set_active.call(active) }
      dbus_method(:Invite, 'in buddy_key:s') { |key| on_invite.call(key) }
      dbus_method(:TakeScreenshot, '') { || on_take_screenshot.call }
    end

    def initialize
      super(object_path)
      @service = make_service
      @service.export(self)
    end 

    private

    def make_service
      ::DBus::SessionBus.instance.request_service("org.laptop.Activity#{Shoes.sugar_activity_id}")
    end

    def object_path
      "/org/laptop/Activity/#{Shoes.sugar_activity_id}"
    end
  end
end
